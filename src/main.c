#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 421;
}

int times_two(int x) {
  return x*2;
}