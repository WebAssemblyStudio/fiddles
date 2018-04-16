#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>

WASM_EXPORT
int main(int argc, char *argv[]) {
  printf("Hello, World!");
  return 0;
}
