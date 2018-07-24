#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(n) {
  int key=0x15ef6e5d;
  int a=0;
  return n==key?(a=1):(a=0);
}
