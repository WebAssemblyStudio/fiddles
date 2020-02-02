#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
double main() {
  double x = 0;
  x = 10293883 * 10292002;
  return x;
}
