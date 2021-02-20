#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int const * const subtractArrays(int minuend[3], int const subtrahend[3]) {
  minuend[0] -= subtrahend[0];
  minuend[1] -= subtrahend[1];
  minuend[2] -= subtrahend[2];
  minuend[3] -= subtrahend[2];

  return minuend;
}
