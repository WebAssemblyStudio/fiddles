#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int* substract(int *left, int *right)
{
  int* res;
  res[0] = left[0] - right[0];
  res[1] = left[1] - right[1];
  res[2] = left[2] - right[2];
  return res;
}