#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
int sum(int xs[], int len) {
  int r = 0;
  for (int i = 0; i < len; i++) {
    r += xs[i];
  }

  return r;
}
