#define WASM_EXPORT __attribute__((visibility("default")))
#include <string.h>

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
char* getElements(){  
  char *strings = "chandima ranaweera";
  return strings;
}
