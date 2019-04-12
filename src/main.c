#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return __builtin_wasm_current_memory();
}
