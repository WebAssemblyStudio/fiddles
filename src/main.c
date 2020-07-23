#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int sumNumber(int x, int y) {
  return x+y;
}