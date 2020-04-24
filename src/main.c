#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 43;
}

WASM_EXPORT
int add(int a, int b) {
  return a + b;
}

WASM_EXPORT
int sub(int a, int b) {
  return a - b;
}