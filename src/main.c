#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

WASM_EXPORT
uint32_t run( uint32_t val ) {
  if ( val > 0xFFFFEF12 ) {
    void* addr = &val;
    void* addr2 = (void*) ( ( (uint32_t) addr ) + 2 );

    if ( *((uint8_t *) addr2) > 0xEE ) {
      return 1;
    } else {
      return 2;
    }
  } else {
    return 1;
  }
}
