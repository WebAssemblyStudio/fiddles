
#define WASM_EXPORT __attribute__((visibility("default")))

int fib_impl(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib_impl(n-1) + fib_impl(n-2);
}

WASM_EXPORT
int process(int n) {
  int res = fib_impl(n);
  return res;
}


