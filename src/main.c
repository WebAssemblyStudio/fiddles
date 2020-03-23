#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

int add(int a, int b) {
  return a + b; 
}
