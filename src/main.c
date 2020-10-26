#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int i = 0;
  for(int d = 0; d < 100; d++){
    i += rand();
  }

  return i;
}
