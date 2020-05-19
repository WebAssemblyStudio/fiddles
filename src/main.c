#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

WASM_EXPORT
int fib( uint32_t n ) {
  if ( n <= 1 ) {
    return n;
  } else {
    return fib( n - 1 ) + fib( n - 2 );
  }
}

WASM_EXPORT
int fib2( uint32_t n ) {
  if ( n <= 1 ) {
    return n;
  } else {
    uint32_t a = 0;
    uint32_t b = 1;

    for ( uint32_t i = 2; i <= n; i++ ) {
      uint32_t c = a + b;
      a = b;
      b = c;
    }

    return b;
  }
}
