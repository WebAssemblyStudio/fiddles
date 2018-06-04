#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int wasmFib(int n) {
  int fiba = 0, fibb = 1, current = 0;
  for(int i = 0; i <= n; ++i) {
    current = fiba + fibb;
    fiba = fibb;
    fibb = current;
  }
  return current;
}
