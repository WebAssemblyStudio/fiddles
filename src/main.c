#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int calc(int min, int max) {
  return min*max;
}
