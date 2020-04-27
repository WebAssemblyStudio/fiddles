#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

uint32_t gcd( uint32_t a, uint32_t b ) {
  if ( b == 0 ) {
    return a;
  } else {
    return gcd( b, a % b );
  }
}

WASM_EXPORT
int run( uint32_t x ) {
  return gcd( x, 2 * x );
}
