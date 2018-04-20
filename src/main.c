#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int n = 1;
  return ++n;
}
