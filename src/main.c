#define WASM_EXPORT __attribute__((visibility("default")))

typedef unsigned int size_t;

#define SIZE 256U
unsigned int IMAGE[SIZE][SIZE];

enum Direction { DIRUP, DIRLEFT, DIRRIGHT, DIRDOWN };

typedef struct { size_t x; size_t y; enum Direction dir; } Ant;

Ant ANT;

WASM_EXPORT void * get_image() { return IMAGE; }

WASM_EXPORT
unsigned int get_size() { return SIZE; }

unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 0x100 * g + 0x1000 * b + 0xff000000;
}

unsigned int black() { return 0xff000000; }

unsigned int white() { return 0xffffffff; }

WASM_EXPORT
void initialize() {
  for (size_t i = 0 ; i != SIZE ; ++i) {
    for (size_t j = 0 ; j != SIZE ; ++j) {
      IMAGE[i][j] = white();
    }
  }

  ANT.x = SIZE / 2;
  ANT.y = SIZE / 2;
}

void AntChangeDirection(Ant * ant, int toTheLeft) {
  switch (ant->dir) {
    case DIRUP:     ant->dir = toTheLeft ? DIRLEFT  : DIRRIGHT; break;
    case DIRDOWN:   ant->dir = toTheLeft ? DIRRIGHT : DIRLEFT ; break;
    case DIRLEFT:   ant->dir = toTheLeft ? DIRDOWN  : DIRUP   ; break;
    case DIRRIGHT:  ant->dir = toTheLeft ? DIRUP    : DIRDOWN ; break;
  }
}

void AntAdvance(Ant * ant) {
    switch (ant->dir) {
    case DIRUP:
      ant->y -= 1;
      break;
    case DIRDOWN:
      ant->y += 1;
      break;
    case DIRLEFT:
      ant->x -= 1;
      break;
    case DIRRIGHT:
      ant->x += 1;
      break;
  }
}


WASM_EXPORT
void frame_advance() {
  if (ANT.x < 0 || ANT.x >= SIZE || ANT.y < 0 || ANT.y >= SIZE)
    return;

  int isOnBlack = IMAGE[ANT.x][ANT.y] == black();

  IMAGE[ANT.x][ANT.y] = isOnBlack ? white() : black();

  AntChangeDirection(&ANT, isOnBlack);
  AntAdvance(&ANT);
}



