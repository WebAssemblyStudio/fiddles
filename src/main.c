#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdio.h>

WASM_EXPORT
int main() {
  int a = 2;
  float b = 3;
  char* c = &b;
  printf("%d %d %d %d\n", c[0],c[1],c[2],c[3]);
  return 42;
}
