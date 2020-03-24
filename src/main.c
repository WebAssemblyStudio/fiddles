#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int factorial(int n) {
  if(n==1) {
    return n;
  } else {
    return n * factorial(n-1);
  }
}