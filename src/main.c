#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;
int xf = 100;
int yf = 100;
int rotationF = 0; // haut 0 / droite 1 / bas 2 / gauche 3

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
      BUFFER[y][x][R] = 0;
      BUFFER[y][x][G] = 0;
      BUFFER[y][x][B] = 0;
      BUFFER[y][x][A] = 255;
    }
  }
  majPosition();
}

WASM_EXPORT
void majPosition(){
  BUFFER[xf][yf][R] = 255;
  BUFFER[xf][yf][G] = 255;
  BUFFER[xf][yf][B] = 255;
}

void haut(){
  xf--;
}

void bas(){
  xf++;
}

void droite(){
  yf++;
}

void gauche(){
  if(yf-1 > )
  yf--;
}

