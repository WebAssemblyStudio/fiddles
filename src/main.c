#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
#include <stdio.h>

int main(char **argv, int argc) {
  while (argc > 0) {
    printf("argv: %s\n", argv[--argc]);
  }
  return 0;
}