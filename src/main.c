#define WASM_EXPORT __attribute__((visibility("default")))

int foo(void) {
  return 45 + 569;
}

WASM_EXPORT
int main() {
  return foo();
}
