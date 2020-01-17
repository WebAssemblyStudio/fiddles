
#include <stdio.h>
#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main()
{
 
  float c;
  int a = 345;
  int b = 6843;
 
  c = sqrt(a*a + b*b);

  return c;
}