#define WASM_EXPORT __attribute__((visibility("default")))


double fact(int i) {
  long long n = 1;
  for (;i > 0; i--) {
    n *= i;
  }
  return (double)n;
}

WASM_EXPORT
int main() {
  return fact(14);
}

