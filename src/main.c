#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>

WASM_EXPORT
int main() {
  printf("42, the secret to life, the universe and everything....");
  return 42;
}
