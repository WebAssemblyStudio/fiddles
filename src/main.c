#define WASM_EXPORT __attribute__((visibility("default")))

// int arr[15];

WASM_EXPORT
int main(int max) {
  int sum = 0;
  int x = 1;
  for (int i = 1; i<max; i++) {
    x = x * 2 + 1;
    sum += x;
  }
  return sum;
}
