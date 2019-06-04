#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
#define SIZE 256
#define HAUT 1
#define DROITE 2
#define BAS 3
#define GAUCHE 4
unsigned int IMAGE[SIZE][SIZE];
int pos_x;
int pos_y;
int direction;

WASM_EXPORT
void init_fourmi() {
  pos_x = SIZE/2;
  pos_y = SIZE/2;
  direction = BAS;
} 

WASM_EXPORT
void* get_image() {
  return (void*)IMAGE;
}

WASM_EXPORT
unsigned int get_size() {
  return SIZE;
}

WASM_EXPORT
unsigned int get_x() {
  return pos_x;
}

WASM_EXPORT
unsigned int get_y() {
  return pos_y;
}

WASM_EXPORT
unsigned int get_direction() {
  return direction;
}

WASM_EXPORT
int get_couleur() {
  return IMAGE[pos_x][pos_y];
}

unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 256*g + 256*256*b + 0xff000000;
}

WASM_EXPORT
void* fill_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = rgb(255, 255, 255);
    }
  }
}

void set_position(x, y) {
  pos_x = x;
  pos_y = y;

  if(pos_x >= SIZE) {
    pos_x = SIZE;
  } else if(pos_x < 0) {
    pos_x = 0;
  }

  if(pos_y >= SIZE) {
    pos_y = SIZE;
  } else if(pos_y < 0) {
    pos_y = 0;
  }
}

void set_direction(dir) {
  direction = dir;
}

void set_couleur(couleur) {
  IMAGE[pos_x][pos_y] = couleur;
}

WASM_EXPORT
void mouvement_fourmi() {
  if(IMAGE[pos_x][pos_y] == rgb(0,0,0)) {
    switch(direction) {
    case HAUT: // regarde vers le haut - 1
      set_direction(GAUCHE);
      set_couleur(rgb(255, 255, 255));
      set_position(pos_x, pos_y-1);
      break;
    case DROITE: // regarder vers la droite - 2
      set_direction(HAUT);
      set_couleur(rgb(255, 255, 255));
      set_position(pos_x-1, pos_y);
      break;
    case BAS: // 3 bas
      set_direction(DROITE);
      set_couleur(rgb(255, 255, 255));
      set_position(pos_x, pos_y+1);
      break;
    case GAUCHE: // 4 gauche
      set_direction(BAS);
      set_couleur(rgb(255, 255, 255));
      set_position(pos_x+1, pos_y);
      break;
    }
  } else if(IMAGE[pos_x][pos_y] == rgb(255,255,255)) {
    switch(direction) {
    case HAUT: // regarde vers le haut
      set_direction(DROITE);
      set_couleur(rgb(0, 0, 0));
      set_position(pos_x, pos_y+1);
      break;
    case DROITE: // regarder vers la droite
      set_direction(BAS);
      set_couleur(rgb(0, 0, 0));
      set_position(pos_x+1, pos_y);
      break;
    case BAS:
      set_direction(GAUCHE);
      set_couleur(rgb(0, 0, 0));
      set_position(pos_x, pos_y-1);
      break;
    case GAUCHE:
      set_direction(HAUT);
      set_couleur(rgb(0, 0, 0));
      set_position(pos_x-1, pos_y);
      break;
    }
  }
}

WASM_EXPORT
void steps_fourmi(int nbStep) {
  for(int i = 0 ; i < nbStep ; i++) {
    mouvement_fourmi();
  }
}
