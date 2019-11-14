#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int finonacci(int x) {
  if (x == 1 || x == 2) {
    return 1;
  }
  return finonacci(x - 1) + finonacci(x  - 2);
}
