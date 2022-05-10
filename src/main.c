// #include <stdlib.h>

#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;

const int NORD = 1;
const int EST = 2;
const int SUD = 3;
const int OUEST = 4;
int direction = NORD;
int xPos = SIZE / 2;
int yPos = SIZE / 2;


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
}

void colorBlack() {
  BUFFER[yPos][xPos][R] = 0;
  BUFFER[yPos][xPos][G] = 0;
  BUFFER[yPos][xPos][B] = 0;
}

void colorWhite() {
  BUFFER[yPos][xPos][R] = 255;
  BUFFER[yPos][xPos][G] = 255;
  BUFFER[yPos][xPos][B] = 255;
}

void turnLeft() {
  direction = (direction - 1) % 4;
}

void turnRight() {
  direction = (direction + 1) % 4;
}

WASM_EXPORT
int getDirection() {
  return direction;
}

WASM_EXPORT
int getXPos() {
  return xPos;
}

WASM_EXPORT
int getYPos() {
  return yPos;
}

int goStraight() {
  switch(direction) {
    case NORD:
      if (yPos <= 0) return 1;
      yPos--;
      break;
    case SUD:
      if (yPos >= SIZE) return 1;
      yPos++;
      break;
    case EST:
      if (xPos >= SIZE) return 1;
      xPos++;
      break;
    case OUEST:
      if (xPos <= 0) return 1;
      xPos--;
      break;
  }
  return 0;
}

WASM_EXPORT
void avancer() {
  int color = BUFFER[yPos][xPos][R];
  if (color == 255) {
    colorBlack();
    turnLeft();
  }
  else if (color == 0) {
    colorWhite();
    turnRight();
  }
  int done = goStraight();
  //if (done == 1) exit(1);
}

