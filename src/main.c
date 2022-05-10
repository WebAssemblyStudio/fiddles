#include <stdio.h>
#include <stdlib.h>

#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;
char orientationFourmi = 'h'; //h haut, b bas, d droite, g gauche
int posX = 0;
int posY = 0;

WASM_EXPORT
void* get_offset() {
  return &BUFFER;
}

WASM_EXPORT
int get_size() {
  return SIZE;
}

void deplacementDroite(){
  switch (orientationFourmi){
    case 'h': //haut
            posX++;
            orientationFourmi = 'd';
          break;

    case 'b': //bas
          posX--;
          orientationFourmi = 'g';
          break;

    case 'd': // droite
          posY--;
          orientationFourmi = 'b';
          break;

    case 'g': // gauche
          posY++;
          orientationFourmi = 'd';
          break;
  }
}

void deplacementGauche(){
  switch (orientationFourmi){
    case 'h': //haut
          posX--;
          orientationFourmi = 'g';
          break;

    case 'b': //bas
          posX++;
          orientationFourmi = 'd';
          break;

    case 'd': // droite
          posY++;
          orientationFourmi = 'h';
          break;

    case 'g': // gauche
          posY--;
          orientationFourmi = 'b';
          break;
  }
}

void deplacementFourmi(){
  if(BUFFER[posX][posY][R] == 255){
    BUFFER[posX][posY][R] = 0;
    BUFFER[posX][posY][G] = 0;
    BUFFER[posX][posY][B] = 0;
    deplacementDroite();

  } else if(BUFFER[posX][posY][R] == 0){
    BUFFER[posX][posY][R] = 255;
    BUFFER[posX][posY][G] = 255;
    BUFFER[posX][posY][B] = 255;
    deplacementGauche();

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

  posX = rand()%SIZE;
  posY = rand()%SIZE;


  orientationFourmi = 0;
}

WASM_EXPORT
void boucle(){
  while(posX > 0 && posX < SIZE && posY > 0 && posY < SIZE){
    deplacementFourmi();
  }
}

