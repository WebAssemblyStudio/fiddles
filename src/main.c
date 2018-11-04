#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int fib(int x) {
  if (x <= 1) return x;
  return fib(x - 1) + fib(x - 2);
}
