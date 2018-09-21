#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int twice(int x) {
  return x * 2;
}
