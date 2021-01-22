#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
int add(int a, int b) {
        return a + b;
}
WASM_EXPORT
int square (int x) {
   return x * x;
 }
