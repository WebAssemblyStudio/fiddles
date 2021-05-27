#define WASM_EXPORT __attribute__((visibility("default")))

int fac(int n) {
  return n <= 1 ? 1 : n * fac(n - 1);
}

WASM_EXPORT
int main() {
  return fac(6);
}
