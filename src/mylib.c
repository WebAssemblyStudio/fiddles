#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int isDivisibleBy(int value, int divisor) {
  return value % divisor == 0 ? 1 : 0;
}
