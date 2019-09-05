#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <errno.h>
WASM_EXPORT
int main() {


  double x = 1024, fraction;
   //int arr[100];
   int e;
   
   
   fraction = frexp(x, &e);
   
  return e;
}
