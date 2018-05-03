#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

WASM_EXPORT
int main() {
  printf("Hello Ther %i\n", 42);

  return 42;
}
