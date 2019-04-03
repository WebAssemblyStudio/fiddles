#include <cmath>

#define WASM_EXPORT extern "C" __attribute__((visibility("default")))

#define MAX_SIDE 32

unsigned char memory[0xA00000]; // 10M
unsigned char* buffer;
unsigned char* db;
unsigned char* db_write_ptr;
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
  unsigned int new_width;
  unsigned int new_height;
  if (input.width > input.height) {
    new_width = MAX_SIDE;
    new_height = 1.0 * input.height * new_width / input.width;
  } else {
    new_height = MAX_SIDE;
    new_width = 1.0 * input.width * new_height / input.height;
  }
  float pixel_size_x = 1.0f * input.width / new_width;
  float pixel_size_y = 1.0f * input.height / new_height;
  *reinterpret_cast<unsigned int*>(output) = new_width;
  *reinterpret_cast<unsigned int*>(output+4) = new_height;
  offset += 8;
  for (unsigned int y = 0; y < new_height; y++) {
    for (unsigned int x = 0; x < new_width; x++) {
      unsigned int pixel_summary = 0;
      unsigned int pixels_total = 0;
      for (unsigned int pixel_y = 0; pixel_y < pixel_size_y; pixel_y++) {
        if (y * pixel_size_y + pixel_y >= input.height) {
          break;
        }
        for (unsigned int pixel_x = 0; pixel_x < pixel_size_x; pixel_x++) {
          if (x * pixel_size_x + pixel_x >= input.width) {
            break;
          }
          pixel_summary += input.get_pixel(x * pixel_size_x + pixel_x, y * pixel_size_y + pixel_y);
          pixels_total++;
        }
      }
      *(output + offset++) = pixel_summary / pixels_total;
    }
  }
  return offset;
}

WASM_EXPORT void set_ptrs(const unsigned int buffer_ptr, const unsigned int db_ptr) {
  buffer = memory + buffer_ptr;
  db = memory + db_ptr;
  db_write_ptr = db;
}

WASM_EXPORT unsigned int get_memory_ptr() {
  return reinterpret_cast<unsigned int>(memory);
}

WASM_EXPORT unsigned int get_buffer_ptr() {
  return reinterpret_cast<unsigned int>(buffer);
}

WASM_EXPORT unsigned int get_db_ptr() {
  return reinterpret_cast<unsigned int>(db);
}

WASM_EXPORT unsigned int get_db_write_ptr() {
  return reinterpret_cast<unsigned int>(db_write_ptr);
}

WASM_EXPORT void on_write_to_db(const unsigned int size) {
  db_write_ptr += size;
  db_cnt++;
}

WASM_EXPORT double find_buffer_in_db(const unsigned int src_width, const unsigned int src_height) {
  convert_image(image_t(src_width, src_height, buffer, true), memory);
  unsigned int input_width = *reinterpret_cast<unsigned int*>(memory);
  unsigned int input_height = *reinterpret_cast<unsigned int*>(memory + 4);
  unsigned int input_size = input_width * input_height;
  unsigned char* db_read_ptr = db;
  image_t image_input(input_width, input_height, memory + 8, false);
  double min_diff = -1;
  for (unsigned int i = 0; i < db_cnt; i++) {
    unsigned int cmp_width = *reinterpret_cast<unsigned int*>(db_read_ptr);
    unsigned int cmp_height = *reinterpret_cast<unsigned int*>(db_read_ptr + 4);
    if (cmp_width == input_width && cmp_height == input_height) {
      image_t to_compare(input_width, input_height, db_read_ptr + 8, false);
      unsigned int diff = 0;
      for (int y = 0; y < input_height; y++) {
        for (int x = 0; x < input_width; x++) {
          diff += std::abs(1.0 * image_input.get_pixel(x, y) - 1.0 * to_compare.get_pixel(x, y));
        }
      }
      double diff_percentage = 1.0 * diff / input_size;
      if (min_diff == -1 || diff_percentage < min_diff) {
        min_diff = diff_percentage;
      }
    }
    db_read_ptr += 8 + cmp_width * cmp_height;
  }
  return min_diff;
}