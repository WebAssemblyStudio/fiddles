#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT int test(bool x) {
  return x;
}
