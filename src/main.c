#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int fib(n) {
  if (n <= 2) {
    return 1;
  }
  return fib(n - 2) + fib(n - 1);
}



WASM_EXPORT
int fib_tail_rec(int n) {
  return helper(n);
}


int helper(int n, int first, int second) {
  if (n == 1) return first;
  if (n == 2) return second;
  return helper(n - 1, second, first + second);
}