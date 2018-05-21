#include <cstdint>

#define WASM_EXPORT __attribute__((visibility("default")))

union Color {
  uint32_t pack;
  struct {
    uint8_t b;
    uint8_t g;
    uint8_t r;
    uint8_t a;
  };
  Color(uint32_t color) {
    pack = color;
  }
  Color lerp(Color to, float amount) {
    Color color = 0;
    color.r = r * amount + to.r * (1 - amount);
    color.g = g * amount + to.g * (1 - amount);
    color.b = b * amount + to.b * (1 - amount);
    return color;
  }
  Color darken(float amount) {
    Color color = 0;
    color.r = r * amount;
    color.g = g * amount;
    color.b = b * amount;
    return color;
  }
  Color lighten(float amount) {
    Color color = 0;
    color.r = r * amount + 255 * (1 - amount);
    color.g = g * amount + 255 * (1 - amount);
    color.b = b * amount + 255 * (1 - amount);
    return color;
  }
};

/* External function that is implemented in JavaScript. */
extern "C" void putNumber(float c);

int test = 456;
Color background = 0xcdcdcd;

WASM_EXPORT
int main() {
  Color text = 0xcdcdcd;

  putNumber(test);
  putNumber(0);
  putNumber(text.r);
  putNumber(background.r);
}

