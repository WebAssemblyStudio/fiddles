#define WASM_EXPORT __attribute__((visibility("default")))

int dmin( int a, int b ) {
  if ( a < b ) {
    return a;
  } else {
    return b;
  }
}

WASM_EXPORT
int main( int x ) {
  return dmin( 2*x, x );
}
