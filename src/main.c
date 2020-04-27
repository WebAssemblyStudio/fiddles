#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

WASM_EXPORT
int run( uint32_t x ) {
  int c = 0;
  while ( x != 0 ) {
    if (x & 1) {
      c++;
    }
    x >>= 1;
  }
  return c;
}
