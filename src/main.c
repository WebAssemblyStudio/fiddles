#include <stdio.h>
#include <stdlib.h>
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  FILE * f = fopen("file.txt","rb");
  fseek(f,SEEK_END,0);
  size_t size = ftell(f);

  return *(int*)&size;
}
