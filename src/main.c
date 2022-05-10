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
int orientationFourmi = 0; //0 haut, 1 bas, 2 droite, 3 gauche

WASM_EXPORT
void* get_offset() {
  return &BUFFER;
}

WASM_EXPORT
int get_size() {
  return SIZE;
}

void deplacementDroite(orientationFourmi,posX,posY){
  switch (orientationFourmi){
    case 0: //haut
          posX++;
          orientationFourmi = 2;
    case 1: //bas
          posX--;
          orientationFourmi = 3;
    case 2: // droite
          posY--;
          orientationFourmi = 1;
    case 3: // gauche
          posY++;
          orientationFourmi = 0;
  }
}

void deplacementGauche(orientationFourmi,posX,posY){
  switch (orientationFourmi){
    case 0: //haut
          posX--;
          orientationFourmi = 3;
    case 1: //bas
          posX++;
          orientationFourmi = 2;
    case 2: // droite
          posY++;
          orientationFourmi = 0;
    case 3: // gauche
          posY--;
          orientationFourmi = 1;
  }
}


void deplacementFourmi(orientationFourmi,posX,posY){
  if(BUFFER[posX][posY][R] == 255){
    deplacementDroite(orientationFourmi,posX,posY);
  } else if(BUFFER[posX][posY][R] == 0){
    deplacementGauche(orientationFourmi,posX,posY);
  }
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

  BUFFER[posX][posY][R] = 255;
  BUFFER[posX][posY][G] = 255;
  BUFFER[posX][posY][B] = 255;

}

