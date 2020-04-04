#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
char * myfunc(char chr[3], char x, char y) {

  chr[0] = x;
  chr[2] = y;

  return chr;
}
