#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
float loop(delta, i) {
  if (i < 5) {
    return 1;
  } else {
    return delta;
  }
}
