#define WASM_EXPORT __attribute__((visibility("default")))
#include <unistd.h>

const int SIZE = 128;
unsigned char BUFFER[SIZE][SIZE][4];
int pos_x = SIZE/2;
int pos_y = SIZE/2;
int direction = 0;
/**
 * 0 = HAUT
 * 1 = DROITE
 * 2 = BAS
 * 3 = GAUCHE
**/
 
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
void moveAnt() {
  int current_color = BUFFER[pos_y][pos_x][B];
  if (current_color == 0) {
    if (direction == 0) {

    } 
    else if (direction == )
  } else {

  }
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
  BUFFER[pos_y][pos_x][R] = 255;
  BUFFER[pos_y][pos_x][G] = 0;
  BUFFER[pos_y][pos_x][B] = 0;
  BUFFER[pos_y][pos_x][A] = 255;
}
