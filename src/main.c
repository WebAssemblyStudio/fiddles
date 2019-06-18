//#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  return 42;
}

WASM_EXPORT
float squarer(float num) {
  return sqrt(num);
}