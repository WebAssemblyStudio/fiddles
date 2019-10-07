#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main()
{
  double a[] = { 4.8, 2.7, 3.4 };
  printf( "( %f, %f, %f )\n", a[0], a[1], a[2] );
  return 42;
}
