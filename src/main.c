#define WASM_EXPORT __attribute__((visibility("default")))

int aliquot_sum(const int x) {
  int sum = 0;
  for (int j = 1; j < x; ++j) {
    if (x % j == 0) {
      sum += j;
    }
  }
  return sum;
}

WASM_EXPORT
int main() {
  return aliquot_sum(123123123);
}
