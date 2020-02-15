#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int one = 1;

WASM_EXPORT
int add (int a, int b) { return a + b; }

WASM_EXPORT
int main() {
  int baz = 0;
  for (int i = 0; i < 5; i++) { baz += add(baz, 42); }
  return baz;
}