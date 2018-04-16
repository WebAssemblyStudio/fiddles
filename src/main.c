#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdio.h>
#include <math.h>

WASM_EXPORT

int main() {

  while (1) {
    printf("Hello World\n");
  }

  return 42;

}
