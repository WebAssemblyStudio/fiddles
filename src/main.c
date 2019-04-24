#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int square(int x) {
  return x * x;
}

WASM_EXPORT
int main(int x) {
  return square(x - 5);
}

