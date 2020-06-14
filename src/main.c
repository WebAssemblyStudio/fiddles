// Binome : ALVES Mickael p1607349 et AUDART Lucas p1509529
#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>

#define SIZE 300

int posY;
int posX;
int nbIte; // Nombre d'itération
char direction; // H = haut B = bas G = gauche D = droite
unsigned int IMAGE[SIZE][SIZE];
unsigned int GRID[SIZE][SIZE];

WASM_EXPORT
void* get_image() {
  return (void*)IMAGE;
}

WASM_EXPORT
unsigned int get_size() {
  return SIZE;
}

WASM_EXPORT
unsigned int get_nbIte() {
  return nbIte;
}

unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 256*g + 256*256*b + 0xff000000;
}

WASM_EXPORT
void* fill_image() {
  for (int i=0; i<SIZE; i++) {
    for (int j=0; j<SIZE; j++) {
      unsigned int color_case = GRID[i][j];
      IMAGE[i][j] = rgb(255*color_case, 255*color_case, 255*color_case); // Select color black or white
    }
  }
}

WASM_EXPORT
void init(){  
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      GRID[i][j]=1;
    }
  }
  nbIte= 0;
  direction = 'H'; 
  posX =(int) SIZE/2;
  posY =(int) SIZE/2;
}

WASM_EXPORT
void simulation(){
  unsigned int color_case = GRID[posX][posY];
  switch(direction){
    case 'H':
      direction = color_case == 0 ? 'D' : 'G';
      break;
    case 'D':
      direction = color_case == 0 ? 'B' : 'H';
      break;
    case 'B': 
      direction = color_case == 0 ? 'G' : 'D';
      break;
    case 'G':
      direction = color_case == 0 ? 'H' : 'B';
      break;
   }

  switch(direction){ // Bords du monde cycliques
    case 'H':
      posX = posX - 1 >= 0 ? posX-1 : SIZE-1;
      break;
    case 'D':
      posY = posY + 1 < SIZE ? posY + 1 : 0;
      break;
    case 'B':
      posX = posX + 1 < SIZE ? posX + 1 : 0;
      break;
    case 'G':
      posY = posY - 1 >= 0 ? posY - 1 : SIZE-1;
      break;
  }

  GRID[posX][posY] = GRID[posX][posY] == 0 ? 1 : 0;
  nbIte = nbIte + 1; 
}
