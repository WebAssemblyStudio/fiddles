#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int _buffer[8];

WASM_EXPORT
int* getBuffer() { return &_buffer[0]; }

WASM_EXPORT
void david() {
  _buffer[0] = 'd';
  _buffer[1] = 'a';
  _buffer[2] = 'v';
  _buffer[3] = 'i';
  _buffer[4] = 'd';
  _buffer[5] = 0;
}
