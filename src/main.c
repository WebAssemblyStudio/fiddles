#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int mul(int a, int b) {
  return a * b;
}
