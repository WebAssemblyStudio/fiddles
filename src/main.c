#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
void main(int loopCount) {
  for (int i=0 ; i <= loopCount ; i++) {
    sqrt(i);
  }
  return;
}