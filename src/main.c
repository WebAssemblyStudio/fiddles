#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdint.h>

typedef int bool;

char data[ 10 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

WASM_EXPORT
char* ptr( ) {
  return data;
}

bool streq( char* a, char* b ) {
  while ( *a != 0 && *b != 0 ) {
    if ( *a != *b ) {
      return 0;
    }
    a++;
    b++;
  }
  return *a == *b;
}

WASM_EXPORT
uint32_t run( uint32_t ptr ) {
  char* input = (char *) ptr;
  return streq( input, "a" );
}
