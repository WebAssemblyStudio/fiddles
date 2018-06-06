#define WASM_EXPORT __attribute__((visibility("default")))
include <range>;

WASM_EXPORT
float* main(float *data, int length) {
  return range(data);
}
