#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int i;
  int max = 2147483647;
  for(i=0; i<max; i++){
    //
  }
  return 0;
}
