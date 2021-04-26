#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
char value() {
  return 'W';
}
