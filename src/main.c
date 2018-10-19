#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
void squareEach(int* p, int lim) {
  for (int i = 0; i < lim; i++) {
    int val = p[i];
    p[i] = val * val;
  }
}
