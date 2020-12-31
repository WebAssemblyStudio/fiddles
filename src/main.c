#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return add(5, 5+5);
}

int add(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
  return a + b;
}
