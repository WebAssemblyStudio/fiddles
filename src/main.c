#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;


enum direction { NORD, EST, SUD, OUEST };

struct Fourmisse {
  unsigned int x,y;
  enum direction d;
};

struct Fourmisse avance(struct Fourmisse f) {
    switch(f.d) {
      case NORD:
        f.y++;
        break;
      case EST:
        f.x++;
        break;
      case SUD:
        f.y--;
        break;
      case OUEST:
        f.x--;
        break;
    }
    return f;
  }

struct Fourmisse f;

WASM_EXPORT
void init() {
  for (int y=0; y<SIZE; y++) {
    for (int x=0; x<SIZE; x++) {
      BUFFER[y][x][R] = 255;
      BUFFER[y][x][G] = 255;
      BUFFER[y][x][B] = 255;
      BUFFER[y][x][A] = 255;
    }
  }
  f.x = SIZE/2;
  f.y = SIZE/2;
  f.d = NORD;
}

WASM_EXPORT
void move() {
  unsigned int x = f.x;
  unsigned int y = f.y;
  if(BUFFER[x][y][R] != 0) { //case noir
    f.d++;
    BUFFER[y][x][R] = 0;
    BUFFER[y][x][G] = 0;
    BUFFER[y][x][B] = 0;
    f = avance(f);
  } else { // case blanche
    f.d--;
    BUFFER[y][x][R] = 255;
    BUFFER[y][x][G] = 255;
    BUFFER[y][x][B] = 255;
    f = avance(f);
  }
}

WASM_EXPORT
void* get_offset() {
  return &BUFFER;
}

WASM_EXPORT
int get_size() {
  return SIZE;
}
