#include <stdio.h>
#include <string>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
char* main() {
  printf("Hello");
  return "23";
}
