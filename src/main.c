#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int add(int a, int b) {
  return a + b;
}

WASM_EXPORT greet() {
 return "hello world";
}
