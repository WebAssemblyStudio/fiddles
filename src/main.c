#define WASM_EXPORT __attribute__((visibility("default")))

int add(int a, int b) {
  return a + b;
}

WASM_EXPORT
int main() {
  return add(3, 4);
}
