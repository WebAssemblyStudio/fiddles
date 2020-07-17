#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
double fibo(double n){
  if (n < 2)
    return 1;
  else
    return fibo(n-1) + fibo(n-2);
}