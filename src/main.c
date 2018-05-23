#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  if (1)
    return 2;
  else
    return 0;
}
