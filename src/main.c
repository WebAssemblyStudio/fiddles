#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return "Hello World";
}

WASM_EXPORT
char* helloWorld() {
  return "Hello World";
}
