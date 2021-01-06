#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdlib.h>
#include <stdio.h>

WASM_EXPORT
int main() {
  //for(int i = 0; i < 5; i++) printf("ok\n");
  return 42;
}
