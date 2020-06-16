#include <stdlib.h>
#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void wasm_log(char* start, int len);

WASM_EXPORT
void* wasm_malloc(int len) {
  return malloc(len);
}

WASM_EXPORT
void run(char* start, int len) {
  char msg[100];
  strcpy(msg,"Salut ");
  strcat(msg,start);
  strcat(msg,"!");
  wasm_log(msg,strlen(msg));
}