#include "script.h"

#define WASM_EXPORT __attribute__((visibility("default")))

int crc(int o, int e, int * items){
  int i,r;
  r=0;

  for(i=o;i<e;i++)
    r=(r<<1)^(items[i]^0x3C);

  return r;
}

WASM_EXPORT
begin
  int i,a;
  int *items=malloc(100);
  for(i=0;i<10;i++)
    items[i]=i;
  
  a=crc(0,10,items);


  return a;
end


