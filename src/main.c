#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int add(int a, int b)
{
  return (a + b / a * b) * (1 * 32909 * 4);
}

WASM_EXPORT
const char *main() {
  return "Ok";
}
