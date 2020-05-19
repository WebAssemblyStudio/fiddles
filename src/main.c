#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

WASM_EXPORT
uint32_t run( uint32_t x ) {
  uint32_t a = 1;
  uint32_t b = 1;

  if ( x > 3 ) {
    a = x;
  } else {
    b = x;
  }

  return a + b;
}
