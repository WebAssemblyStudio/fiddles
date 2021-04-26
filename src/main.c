#define WASM_EXPORT __attribute__((visibility("default")))

int squarer(int n) {
  return n * n;
}

WASM_EXPORT
int main() {
  return squarer(3);
}
