#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int a = 3;
  int b = 5;

  return a + b;
}
