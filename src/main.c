#define WASM_EXPORT __attribute__((visibility("default")))

int h(int k) {
  return k * (k + 3) % 7919;
}

WASM_EXPORT
int benchmark() {
  int k = 12;
  for (int i = 0; i < 100000000; i++) {
    k = h(k);
  }
  return k;
}