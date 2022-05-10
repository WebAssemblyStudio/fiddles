#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;
int posx, posy; // position de la fourmi
int rotation = 0; // 0 = devant, 1 = gauche, 2 = derriere, 3 = droite

WASM_EXPORT
void* get_offset() {
  return &BUFFER;
}

WASM_EXPORT
int get_size() {
  return SIZE;
}

WASM_EXPORT
// Génère une image dans BUFFER de couleur noire
void fill() {
  for (int y=0; y<SIZE; y++) {
    for (int x=0; x<SIZE; x++) {
      BUFFER[y][x][R] = 0;
      BUFFER[y][x][G] = 0;
      BUFFER[y][x][B] = 0;
      BUFFER[y][x][A] = 255;
    }
  }
  posx = SIZE/2;
  posy = SIZE/2;
}

WASM_EXPORT
void avanceFourmi() {
  if(rotation == 0) {
    posx--;
  } else if (rotation == 1) {
    posy--;
  } else if (rotation == 2) {
    posx++;
  } else {
    posy++;
  }
}

WASM_EXPORT
void updateMouvementFourmi() {
  if(BUFFER[posy][posx][R] == 255) { // si la fourmi est dans une case blanche
    if(rotation == 0) { // déplacement 90° droite
      rotation = 3;
    } else {
      rotation--;
    }
    BUFFER[posy][posx][R] = 0;
    BUFFER[posy][posx][G] = 0;
    BUFFER[posy][posx][B] = 0;
  } else {
    if(rotation == 3) { // déplacement 90° gauche
      rotation = 0;
    } else {
      rotation++;
    }
    BUFFER[posy][posx][R] = 255;
    BUFFER[posy][posx][G] = 255;
    BUFFER[posy][posx][B] = 255;
  }
  avanceFourmi();
}

WASM_EXPORT
void update() {
  while(posx > 0 && posx < SIZE && posy > 0 && posy < SIZE) {
    updateMouvementFourmi();
  }
}