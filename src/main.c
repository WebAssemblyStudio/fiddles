#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

WASM_EXPORT
uint32_t run( uint32_t a ) {
  // Always returns 'a'
  if ( a < 0x80 ) {
    return a & 0xFF;
  } else {
    return a;
  }
}
