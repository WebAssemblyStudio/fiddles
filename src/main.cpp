#include <cmath>

#define WASM_EXPORT extern "C" __attribute__((visibility("default")))

#define BUFSIZE 102400 // 100K
#define DBSIZE 10485760 // 10M

#define PIXEL_SIZE 5

unsigned char buffer[BUFSIZE];
unsigned char db[DBSIZE];
unsigned char* db_write_ptr = db;
unsigned int db_cnt = 0;

class image_t {
public:
  const unsigned int width;
  const unsigned int height;
  const unsigned char* pixels;
  const bool rgba;

  image_t(const unsigned int width, const unsigned int height, const unsigned char* pixels, bool rgba) :
    width(width),
    height(height),
    pixels(pixels),
    rgba(rgba)
  {}

  unsigned char get_pixel(const unsigned int x, const unsigned int y) const {
    unsigned int offset = this->width * y + x;
    if (this->rgba) {
      const unsigned char* pixel = this->pixels + offset * 4;
      return (pixel[0] + pixel[1] + pixel[2]) / 3;
    } else {
      return this->pixels[offset];
    }
  }
};

unsigned int convert_image(const image_t& input, unsigned char* output) {
  unsigned int offset = 0;
  unsigned int new_width = std::ceil(1.0f * input.width / PIXEL_SIZE);
  unsigned int new_height = std::ceil(1.0f * input.height / PIXEL_SIZE);
  *reinterpret_cast<unsigned int*>(output) = new_width;
  *reinterpret_cast<unsigned int*>(output+4) = new_height;
  offset += 8;
  for (unsigned int y = 0; y < new_height; y++) {
    for (unsigned int x = 0; x < new_width; x++) {
      unsigned int pixel_summary = 0;
      unsigned int pixels_total = 0;
      for (unsigned int pixel_y = 0; pixel_y < PIXEL_SIZE; pixel_y++) {
        if (y * PIXEL_SIZE + pixel_y >= input.height) {
          break;
        }
        for (unsigned int pixel_x = 0; pixel_x < PIXEL_SIZE; pixel_x++) {
          if (x * PIXEL_SIZE + pixel_x >= input.width) {
            break;
          }
          pixel_summary += input.get_pixel(x * PIXEL_SIZE + pixel_x, y * PIXEL_SIZE + pixel_y);
          pixels_total++;
        }
      }
      *(output + offset++) = pixel_summary / pixels_total;
    }
  }
  return offset;
}

WASM_EXPORT unsigned int get_buffer_ptr() {
  return reinterpret_cast<unsigned int>(buffer);
}

WASM_EXPORT unsigned int get_db_ptr() {
  return reinterpret_cast<unsigned int>(db);
}

WASM_EXPORT void write_buffer_to_db(const unsigned int width, const unsigned int height) {
  db_write_ptr += convert_image(image_t(width, height, buffer, true), db_write_ptr);
  db_cnt++;
}

WASM_EXPORT double find_buffer_in_db(const unsigned int width, const unsigned int height) {
  unsigned int converted_width = std::ceil(1.0 * width / PIXEL_SIZE);
  unsigned int converted_height = std::ceil(1.0 * height / PIXEL_SIZE);
  unsigned int converted_size = converted_width * converted_height;
  unsigned char buffer_converted[8 + converted_size];
  convert_image(image_t(width, height, buffer, true), buffer_converted);
  unsigned char* db_read_ptr = db;
  image_t image_input(converted_width, converted_height, buffer_converted + 8, false);
  double min_diff = -1;
  for (unsigned int i = 0; i < db_cnt; i++) {
    unsigned int width = *reinterpret_cast<unsigned int*>(db_read_ptr);
    unsigned int height = *reinterpret_cast<unsigned int*>(db_read_ptr + 4);
    image_t to_compare(width, height, db_read_ptr + 8, false);
    db_read_ptr += 8 + to_compare.width * to_compare.height;
    if (image_input.width == to_compare.width && image_input.height == to_compare.height) {
      unsigned int diff = 0;
      for (int y = 0; y < image_input.height; y++) {
        for (int x = 0; x < image_input.width; x++) {
          diff += std::abs(1.0 * image_input.get_pixel(x, y) - 1.0 * to_compare.get_pixel(x, y));
        }
      }
      double diff_percentage = 1.0 * diff / converted_size;
      if (min_diff == -1 || diff_percentage < min_diff) {
        min_diff = diff_percentage;
      }
    }
  }
  return min_diff;
}