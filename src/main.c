#define WASM_EXPORT __attribute__((visibility("default")))



int bar() {
  return 55;
}

int foo() {
  int a = bar();
  return a;
}

WASM_EXPORT
int main() {
  int a =foo();
  return a;
}

