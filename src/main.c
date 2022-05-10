#define WASM_EXPORT __attribute__((visibility("default")))

#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;
int posX = 0;
int posY = 0;
char direction[] = {"droite", "gauche", "haut", "bas"};


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
      BUFFER[y][x][R] = x % 256;
      BUFFER[y][x][G] = x % 256;
      BUFFER[y][x][B] = x % 256;
      BUFFER[y][x][A] = 255;
    }
  }
}


WASM_EXPORT
char droite() {
  posX = posX + 1;
  return "bas";
}

WASM_EXPORT
char gauche() {
  posX = posX - 1;
  return "haut";
}

WASM_EXPORT
char haut() {
  posY = posY + 1;
  return "droite";
}

WASM_EXPORT
char bas() {
  posY = posY - 1;
  return "gauche";
}

WASM_EXPORT
void fourmi() {
  int rouge = BUFFER[posX][posY][R];
  int vert = BUFFER[posX][posY][G];
  int bleu = BUFFER[posX][posY][B];
}