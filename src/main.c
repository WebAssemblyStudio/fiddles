#define WASM_EXPORT __attribute__((visibility("default")))

int gcd( int a, int b ) {
  if ( b == 0 ) {
    return a;
  } else {
    return gcd( b, a % b );
  }
}

WASM_EXPORT
int main( ) {
  int x = 24;
  return gcd( x, 2 * x );
}
