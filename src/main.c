#include <stdio.h>

char *c_hello();

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  c_hello();
  return 42;
}

WASM_EXPORT
char *c_hello() {
   return "Hello World"; 
}
