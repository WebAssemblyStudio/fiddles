#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdio.h>

WASM_EXPORT
int main() {
  printf("hello\n");
  return 42;
}
