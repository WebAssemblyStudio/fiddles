#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int _start() {
  printf("test");
  return 42;
}
