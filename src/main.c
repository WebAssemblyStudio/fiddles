#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int squarer(int base) {
  return base * base;
}
