#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdio.h>

WASM_EXPORT
int main() {
  printf("test assembly.\n");
  return 42;
}
