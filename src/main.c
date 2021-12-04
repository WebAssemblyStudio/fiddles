#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
int sum(int *input, int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += input[i];
  }

  return total;
}

WASM_EXPORT
void fill(int *output, int size, int data) {
  for (int i = 0; i < size; i++) {
    output[i] = data;
  }
}
