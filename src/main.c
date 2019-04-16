#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int fib(n) {
  if (n < 2) {
    return 1;
  }
  return fib(n - 2) + fib(n - 1);
}

