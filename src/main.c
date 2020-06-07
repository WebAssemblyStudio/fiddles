#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

WASM_EXPORT
uint32_t run( uint32_t x ) {
  if ( x < 32 ) { // max `x` = 31 = 0b11111
    // So: ( x >> 5 ) == 0
    uint32_t v = ( x >> 5 ) & 1;
    if ( v == 0 ) {
      return 5;
    } else {
      return 42;
    }
  } else {
    return 99;
  }
}
