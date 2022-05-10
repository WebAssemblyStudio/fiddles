#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;
int orientationFourmi = 0; //0 ouest, 1 nord, 2 est, 3 gauche

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

  //int posX = rand() % SIZE;
  //int posY = rand() % SIZE;

  int posX = SIZE/2;
  int posY = SIZE/2;

  BUFFER[posY][posX][R] = 255;
  BUFFER[posY][posX][G] = 255;
  BUFFER[posY][posX][B] = 255;

}

void droite(posX, posY){

}
