#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  /*for( int i = 1; i < 42; i++ )
  {
    printf( "%d", i );
    Sleep(10000);
  }*/
  return 42;
}
