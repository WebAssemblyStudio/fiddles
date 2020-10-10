#include<stdio.h>
#define WASM_EXPORT __attribute__((visibility("default")))
WASM_EXPORT
int main() {
  FILE *fp=fopen("main.c","r");
  char c;
  while(1)
  {
    c=fgetc(fp);
    if(c==EOF)
      break;
    printf("%c",c);
  }
  return 0;
}
