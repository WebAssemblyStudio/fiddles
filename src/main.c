#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
char* helloWord() {
  return "helloWord";
}

WASM_EXPORT
int add(a, b) {
  return a + b;
}

WASM_EXPORT
int minus(a, b) {
  return a - b;
}
