#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 23;
}

WASM_EXPORT
int getNumber(int num1) {
  return num1;
}