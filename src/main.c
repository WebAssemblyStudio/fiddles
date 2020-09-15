#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int fib(int num) {
  if(num == 0) return 0;
  if(num == 1) return 1;

  return fib(num-1) + fib(num-2);
}
