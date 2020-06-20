#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int fib_rec(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n == 2) return 1;
  return fib_rec(n-1) + fib_rec(n-2);
}

WASM_EXPORT
int fib(int n) {
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