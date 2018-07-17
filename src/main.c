#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int m = 32398;
  for (int i = 0; i < 64; i++) {
    m ^= m << 20;
    m ^= m >> 17;
    m ^= m << 5;
  }
  return m;
}
