#define WASM_EXPORT __attribute__((visibility("default")))

class testClass {
  int someInt { return 12; }
};

WASM_EXPORT
int main() {

  someInt test;
  int teat = test.someInt();
  return 42;
}
