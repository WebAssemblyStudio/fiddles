#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(int argc, char '*' argv) {
  int total = 0;
  for (int i = 0; i < argc; i++) {
    total = total + argv[i];
  }
  return total;
}
