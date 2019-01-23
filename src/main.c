#define WASM_EXPORT __attribute__((visibility("default")))
#define WASM_IMPORT __attribute__((visibility("default")))

WASM_IMPORT
void import1(int a, int b);

WASM_EXPORT

int add (int x, int y) {
  import1(2, 5);
  return x + y;
}

WASM_EXPORT

int square (int x) {
  return x * x;
}
