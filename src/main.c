#include <stdio.h>
#define WASM_EXPORT __attribute__((visibility("default")))

float cosf(float x)
{
  return 1.0f;
}

WASM_EXPORT
int main() {
  printf("Hello, World! %f\n", cosf(3.1415f));
  return 0;
}
