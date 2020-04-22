#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int factorial(int n) {
  int i;
  int result = 1;
  for (i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}
