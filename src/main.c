#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 2;
float data[SIZE];

WASM_EXPORT
float* getData() {
  return &data[0];
}

WASM_EXPORT
void vec2add(float xa, float xb, float ya, float yb) {
  data[0] = xa + xb;
  data[1] = ya + yb;
}

