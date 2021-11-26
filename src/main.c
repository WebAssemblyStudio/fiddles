#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int *a = -1;
  *a = 1;
}
