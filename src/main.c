#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
int Add(int a, int b)
{
  return a + b;
}
