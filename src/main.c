#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int j = 0;
  for(int i=0;i<1000000000;i++) {
    j++;
  }
  return j;
}
