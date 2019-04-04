#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {

  int i=0;
  i++;


  return i;
}
