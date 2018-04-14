#include <stdio.h>
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int j = 0;
  for( int i = 1; i < 1000000; i++ )
  {
    printf("Hello, world!\n");
    j += i;
  }
  return j;
}
