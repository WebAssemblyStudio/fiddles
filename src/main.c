#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  int i,a;
  int *items=malloc(100);
  for(i=0;i<10;i++)
    items[i]=i;
  
  a=32;

  for(i=3;i<6;i++)
    a=(a<<1)+(items[i]^0x3C);

  return a;
}


