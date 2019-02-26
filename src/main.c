#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(int argc, char** argv) {
  int x = argc + 1;
  return x;
}
