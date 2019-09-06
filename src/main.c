#include<stdio.h>
#define WASM_EXPORT __attribute__((visibility("default")))


WASM_EXPORT
int sum_n(int  x){
  int sum = 0;
  while(x--){
    sum = sum + x;
  }
  return sum;
}