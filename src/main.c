#define WASM_EXPORT __attribute__((visibility("default")))
int C = 0;
char* string = "Unchanged variable";

WASM_EXPORT
int check() {
  return C;
}

WASM_EXPORT
char* _Rstring() {
  return string;
}

WASM_EXPORT
char* _PrintF(char* str) {
  string = str;
  C = 1;
}

WASM_EXPORT
char* printText() {
 _PrintF("Try Changing this from the .wasm!");
  char* beans = "Good luck!";
  return beans;
}