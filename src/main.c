#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int test(int a) {
  return 42 + a;
}
