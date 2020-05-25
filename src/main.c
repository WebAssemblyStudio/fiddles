#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

uint32_t pow_u32( uint32_t a, uint32_t b ) {
  uint32_t prod = 1;
  for ( uint32_t i = 0; i < b; i++ ) {
    prod *= a;
  }
  return prod;
}

// All these functions compute (a+1)**4

WASM_EXPORT
uint32_t run1( uint32_t a ) {
  return pow_u32( a + 1, 4 );
}

WASM_EXPORT
uint32_t run2( uint32_t a ) {
  a = ( a + 1 );
  a = a * a;
  return a * a;
}

WASM_EXPORT
uint32_t run3( uint32_t a ) {
  return a * a * a * a + 4 * a * a * a + 6 * a * a + 4 * a + 1;
}

WASM_EXPORT
uint32_t run4( uint32_t a ) {
  // This implementation was obtained by compiling `run3` to WASM, and then
  // manually reconstructing the C code from that.
  uint32_t b = a << 2;
  a = a * a;
  return ( b | 1 ) + a * ( a + b + 6 );
}
