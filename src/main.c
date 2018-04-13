#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int compute(unsigned int *numbers, int size) {
  for (int i = 0; i < size; i++) {
    numbers[i] *= 2;
  }
  return size;
}
