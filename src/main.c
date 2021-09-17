#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int i;
  for(i=0; i<100000000; i++){
    //
  }
  return 0;
}
