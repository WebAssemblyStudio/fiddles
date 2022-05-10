#define WASM_EXPORT __attribute__((visibility("default")))
#include <unistd.h>

const int SIZE = 128;
unsigned char BUFFER[SIZE][SIZE][4];
int pos_x = SIZE/2;
int pos_y = SIZE/2;
int direction = 0;
int current_color = 196;
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
void move_ant() {
  if (current_color == 255) {
    // Change color
    BUFFER[pos_y][pos_x][R] = 196;
    BUFFER[pos_y][pos_x][G] = 196;
    BUFFER[pos_y][pos_x][B] = 196;

    if (direction == 0) {
      pos_x = pos_x + 1;
      direction = 1;
    } 
    else if (direction == 1) {
      pos_y = pos_y - 1;
      direction = 2;
    }
    else if (direction == 2) {
      pos_x = pos_x - 1;
      direction = 3;
    }
    else if (direction == 3) {
      pos_y = pos_y + 1;
      direction = 0;
    }
  } else {
    // Change color
    BUFFER[pos_y][pos_x][R] = 0;
    BUFFER[pos_y][pos_x][G] = 0;
    BUFFER[pos_y][pos_x][B] = 255;

    if (direction == 0) {
      pos_x = pos_x - 1;
      direction = 3;
    } 
    else if (direction == 1) {
      pos_y = pos_y + 1;
      direction = 0;
    }
    else if (direction == 2) {
      pos_x = pos_x + 1;
      direction = 1;
    }
    else if (direction == 3) {
      pos_y = pos_y - 1;  
      direction = 2;
    }
  }

  current_color = BUFFER[pos_y][pos_x][B];

  // Color ant
  BUFFER[pos_y][pos_x][R] = 255;
  BUFFER[pos_y][pos_x][G] = 0;
  BUFFER[pos_y][pos_x][B] = 0;
}

WASM_EXPORT
// Génère une image dans BUFFER
void fill() {
  for (int y=0; y<SIZE; y++) {
    for (int x=0; x<SIZE; x++) {
      BUFFER[y][x][R] = 196;
      BUFFER[y][x][G] = 196;
      BUFFER[y][x][B] = 196;
      BUFFER[y][x][A] = 196;
    }
  }
  BUFFER[pos_y][pos_x][R] = 255;
  BUFFER[pos_y][pos_x][G] = 0;
  BUFFER[pos_y][pos_x][B] = 0;
  BUFFER[pos_y][pos_x][A] = 255;

  current_color = 196;
}
