#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int add(int a, int b) {
  return a + b * a - b / 23 + 1;
}

WASM_EXPORT
int main(int x) {
  int y = add(x, 32);
  return add(y, add(95, x));
}
