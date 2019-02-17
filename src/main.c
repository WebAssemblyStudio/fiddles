#define WASM_EXPORT __attribute__((visibility("default")))

char s[]= "Abc";
WASM_EXPORT
char test() {
  return s[0];
}
