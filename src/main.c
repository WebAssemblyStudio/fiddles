#define WASM_EXPORT __attribute__((visibility("default")))

extern void* memory;

WASM_EXPORT
void squareEach(int lim) {
  int* mem32 = memory;
  for (int i = 0; i < lim; i++) {
    int val = mem32[i];
    mem32[i] = val * val;
  }
}
