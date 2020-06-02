// 
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int my_func() {
  return 42;
}
