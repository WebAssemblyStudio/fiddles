#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
#include <sys/uio.h>

WASM_EXPORT
int main() {
  // printf("Hello World!\n") ;
  return 43;
}
