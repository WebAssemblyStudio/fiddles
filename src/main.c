#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>
#include <stdio.h>

WASM_EXPORT
int main() {
  float a = 20.0 / 3;
  //printf("round(a) = %f",round(a));
  return round(a);
  return 111;
}
