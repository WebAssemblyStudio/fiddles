#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
float avgRoot(unsigned char * arr, int length) {
  float avg = 0.0f;
  for (int i = 0; i < length; i++) {
    avg = (avg + (float)arr[i]) / 2.0f;
  }
  return avg;
}
