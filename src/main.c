#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
#include <string.h>
WASM_EXPORT
char* outName(char *n){    
 char xhName [] = "xuanhun";   
 strcat(n, xhNamhe);   
 return n;
}