#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int i = 1;
  if (i)
    return 2;
  else
    return 0;
}
