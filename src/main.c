#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;

const int NORD = 0;
const int EST = 1;
const int SUD = 2;
const int OUEST = 3;
const int direction = NORD;
const int xPos = SIZE / 2;
const int yPos = SIZE / 2;


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
      BUFFER[y][x][R] = 255;
      BUFFER[y][x][G] = 255;
      BUFFER[y][x][B] = 255;
      BUFFER[y][x][A] = 255;
    }
  }
}

WASM_EXPORT
void colorBlack(x, y) {
  BUFFER[y][x][R] = 0;
  BUFFER[y][x][G] = 0;
  BUFFER[y][x][B] = 0;
}

WASM_EXPORT
void colorWhite(x, y) {
  BUFFER[y][x][R] = 255;
  BUFFER[y][x][G] = 255;
  BUFFER[y][x][B] = 255;
}

void avancer() {
  int color = BUFFER[yPos][xPos][R]
  if (color == 255) {
    turnLeft();
    colorBlack();
  }
  else if (color == 0) {
    turnRight();
    colorWhite();
  }
}

