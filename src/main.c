#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
float add(float x, float y) {
  return x+y;
}


WASM_EXPORT
float sub(float x, float y) {
  return x-y;
}


WASM_EXPORT
float div(float x, float y) {
  return x/y;
}


WASM_EXPORT
float mul(float x, float y) {
  return x*y;
}