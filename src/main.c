#include <stdio.h>
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

int add(int a, int b){
  return a+b;
}

int sub(int a, int b){
  return a-b;
}

int main() {
  int a = 1;
  int b = 2;
  int (*vegas)(int, int);
  if(a > b){
    vegas = &add;
  }else{
    vegas = &sub;
  }
  vegas(a,b);
  printf("a = %d\nb = %d", a, b);
  return 42;
}
