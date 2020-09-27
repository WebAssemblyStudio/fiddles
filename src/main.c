#include <stdio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  printf("Hello World\n");
}

WASM_EXPORT
int add42(int num) {
    return num + 42;
}
