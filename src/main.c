#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 3;
}

WASM_EXPORT
char  *c_hello() {
   return "hello mother fucker"; 
}
