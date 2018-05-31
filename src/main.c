#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
double doubleAdd(double a, double b) {
  return 2 * (a + b);
}
