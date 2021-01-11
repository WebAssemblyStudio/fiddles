// #include <stdio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  // printf("Hello World\n");
  return 42;
}

WASM_EXPORT
int sum(int x, int y) {
  return x + y;
}