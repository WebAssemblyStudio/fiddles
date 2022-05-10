#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;
int antPos[2] = {128, 128};
int antDir = 2; // 4 left 2 down 8 up 6 right


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
void init() {
  for (int y=0; y<SIZE; y++) {
    for (int x=0; x<SIZE; x++) {
      BUFFER[y][x][R] = 0;
      BUFFER[y][x][G] = 0;
      BUFFER[y][x][B] = 0;
      BUFFER[y][x][A] = 125;
    }
  }
}

WASM_EXPORT
void putAnt() {
  int x = antPos[0];
  int y = antPos[1];
  
  // if not visited, it's white
  if(BUFFER[y][x][A] == 255) {
    antDir = trunLeft(antDir);
  }
  else {
    antDir = trunRight(antDir);
  }
  BUFFER[y][x][A] = 0;
}

int trunLeft(int x) {
  if(x == 4) return 2;
  if(x == 2) return 6;
  if(x == 6) return 8;
  if(x == 8) return 4;
}

int trunRight(int x) {
  if(x == 4) return 8;
  if(x == 8) return 6;
  if(x == 6) return 2;
  if(x == 2) return 4;
}