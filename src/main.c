#include <math.h> 
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int* _buffer = NULL;
int size;

WASM_EXPORT
int* getBuffer() { return &_buffer[0]; }

WASM_EXPORT
void setBuffer(_size) {
  size = _size;
  _buffer = new int[size];
}

int luminance(int r, int g, int b) {
  return floor (0.299 * r) + (0.587 * g) + (0.114 * b);
}

WASM_EXPORT
void greyscale(){
  for (int i = 0; i < size; i+4) {
    _buffer[i] = _buffer[i+1] = _buffer[i+2] = luminance(_buffer[i], _buffer[i+1], _buffer[i+2]);
  }
}
