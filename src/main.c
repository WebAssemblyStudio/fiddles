#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
int shift(const int a, const int b) {
  return a << b;
}
