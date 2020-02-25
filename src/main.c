#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
float avgRoot(unsigned char * arr, int length) {
  int avg = 0.0f;
  for (int i = 0; i < length; i++) {
    avg += arr[i];
  }
  return avg / (float)length;
}
