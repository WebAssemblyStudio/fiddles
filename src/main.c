#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

long factor(long long n) {
  if(n<=1) return 1;
  return factor(n-1)*n;
}
 