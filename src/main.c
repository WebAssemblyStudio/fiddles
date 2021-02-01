#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

WASM_EXPORT
int add(int a, int b) {
  return a + b;
}