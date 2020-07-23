#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT int add(int x, int y) {
  return x+y;
}