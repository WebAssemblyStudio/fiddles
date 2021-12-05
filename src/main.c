#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT int fib(int n) {
  int a = 0, b = 1;
  if (n > 0) {
    while (--n) {
      int t = a + b;
      a = b;
      b = t;
    }
    return b;
  }
  return a;
}
