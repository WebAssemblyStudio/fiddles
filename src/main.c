#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;

WASM_EXPORT
void* get_offset() {
  return &BUFFER;
}

WASM_EXPORT
int get_size() {
  return SIZE;
}

WASM_EXPORT
// Génère une image dans BUFFER
void fill() {
  for (int y=0; y<SIZE; y++) {
    for (int x=0; x<SIZE; x++) {
      BUFFER[y][x][R] =  0;
      BUFFER[y][x][G] =  0;
      BUFFER[y][x][B] =  0;
    }
  }
  BUFFER[150][0][R] = 0;
  BUFFER[150][0][G] = 0;
}
