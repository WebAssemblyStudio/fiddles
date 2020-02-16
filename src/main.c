#define WASM_EXPORT __attribute__((visibility("default")))

float result[16];
float a[16];
float b[16];

WASM_EXPORT
float * getResultPointer () {
  return result;
}

WASM_EXPORT
float * hi () {
  return a;
}

WASM_EXPORT
void change ( int index, float number ) {
  a[ index ] = number;
}