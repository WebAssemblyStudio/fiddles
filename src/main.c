#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int test = 5 * 10;
  return test;
}
