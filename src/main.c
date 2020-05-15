#include<stdio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  printf("hello world");
  return 42;
}
