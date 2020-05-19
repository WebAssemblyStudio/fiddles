#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

// This function always returns 1
WASM_EXPORT
int run( uint32_t a, uint32_t b, uint32_t c ) {
  if ( a > b ) {
    if ( b > c ) {
      if ( a <= c ) {
        // This can never happen
        return 2;
      }
    }
  }

  return 1;
}
