#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int shift(int *p, int *t, int shiftX, int shiftY, int shiftZ) {

  int shift_i = shiftX + shiftY * 256 + shiftZ * 256 * 256;

  for(int i = 0; i < 256 * 256 * 256; i++) {
      
    int src_i = i;
		int dst_i = i + shift_i;

    p[dst_i] = p[src_i];

  }

  return 1;

}
