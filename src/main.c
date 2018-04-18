#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  println("df");
  return 42;
}
