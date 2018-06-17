#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int testSet(int input) {

  return input *2;

}

WASM_EXPORT
int main() {
  int val = 1;

  return testSet(val)*2;
}
