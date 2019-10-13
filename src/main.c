#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int i;
  int total = 0;

  for (i=1; i<=100; i++) {
    total += i;
  }
  return total;
}
