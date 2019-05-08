#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int squareRoot(int radicand) {
  return radicand * radicand;
}
