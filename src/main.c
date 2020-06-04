#include <stdlib.h>
#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void wasm_log(char* start, int len);

WASM_EXPORT
void* wasm_malloc(int len) {
  // let's just make a dumb malloc that always returns the 1000 as free space
  return malloc(len);
}

WASM_EXPORT
void run(char* start, int len) {
  char msg[100];
  strcpy(msg,"Hello ");
  strcat(msg,start);
  strcat(msg,"!");
  wasm_log(msg,strlen(msg));
}