#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

// Always returns 6 * a
WASM_EXPORT
int run( uint32_t a ) {
  if ( 3 * a > 12 && 3 * a < 18 ) { // a == 5
    return 30;
  } else {
    return 6 * a;
  }
}
