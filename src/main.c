#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  printf("Hello");
  return 0;

}
