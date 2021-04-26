#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
float add(float x, float y) {
  return x + y;
}
