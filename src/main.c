#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;
int posx, posy;
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
  posx = SIZE/2;
  posy = SIZE/2;
  BUFFER[posy][posx][G] = 0;
  BUFFER[posy][posx][B] = 0;
}

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

void updateMouvementFourmi() {
  if(BUFFER[posy][posx][R] == 255) { // si la fourmi est dans une case blanche
    if(rotation == 0) {
      rotation = 3;
    } else {
      rotation--;
    }
    BUFFER[posy][posx][R] = 0;
    BUFFER[posy][posx][G] = 0;
    BUFFER[posy][posx][B] = 0;
  } else {
    if(rotation == 3) {
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