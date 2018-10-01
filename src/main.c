#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int tau(int input) {
  int n = input, i;
  unsigned long long x = 1;

  for(i=1; i<=n; ++i) {
      x *= i;
  }

  return x;
}
