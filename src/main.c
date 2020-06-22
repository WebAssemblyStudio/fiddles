#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
int sumSequence(int n){
  if (n < 2)
    return n;
  else
    return n + sumSequence(n-1);
}

WASM_EXPORT
int fib(int n){
  if (n < 2)
    return n;
  else
    return fib(n-1) + fib(n-2);
}