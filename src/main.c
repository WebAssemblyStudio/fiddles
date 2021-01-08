#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  printf("Hello World!");
  return 0;
}
