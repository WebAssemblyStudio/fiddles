#include <stdio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int a = 0;
  scanf("%d", &a);
  return 42;
}
