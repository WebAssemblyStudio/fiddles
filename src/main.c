#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int a = 10;
  int *p = &a;
  return *p;
}
