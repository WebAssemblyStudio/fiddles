#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int doubler(int input) {
  return 2 * input;
}
