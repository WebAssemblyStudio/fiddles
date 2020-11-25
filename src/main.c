#include <stdio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(int s) {
  return s*2;
}
