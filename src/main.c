#include <stdio.h>
#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))

int data[256 * 256 * 256];
int temp[256 * 256 * 256];

WASM_EXPORT
int* getDataPointer() {

  return &data[0];

}

WASM_EXPORT
int* getTempPointer() {

  return &temp[0];

}

WASM_EXPORT
int test(int *p, int shiftX, int shiftY, int shiftZ) {

  int shift = shiftX + shiftY * 256 + shiftZ * 256 * 256;

  for(int i = 0; i < 256 * 256 * 256; i++) {
      
    int src_i = i;
		int dst_i = i + shift;

    temp[dst_i] = p[src_i];

  }
  
  memcpy(&data, &temp, 256 * 256 * 256 * 4);

  return 0;

}