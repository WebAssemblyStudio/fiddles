#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256
unsigned int IMAGE[SIZE][SIZE];
int noir = 0xff000000;
int blanc = 0;
int aPosX;
int aPosY;
int direction;

WASM_EXPORT
void* get_image() {
  return (void*)IMAGE;
}

WASM_EXPORT
unsigned int get_size() {
  return SIZE;
}

unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 256*g + 256*256*b + 0xff000000;
}

WASM_EXPORT
int getCurColor() {
  return IMAGE[aPosY][aPosX];
}

WASM_EXPORT
void turnLeft () {
  if (direction == 270)
    direction = 0;
  else 
    direction += 90;
}

WASM_EXPORT
void turnRight() {
  if (direction == 0)
    direction = 270;
  else 
    direction -= 90;
}

WASM_EXPORT
void avance () {
  //droite
  if(direction == 0) {
    if (aPosX<SIZE)
      aPosX++;
  }
  //gauche
  if(direction == 180) {
    if (aPosX>0)
      aPosX--;
  }
  //haut
  if(direction == 90) {
    if (aPosY>0)
      aPosY--;
  }
  //bas
  if(direction == 270) {
    if (aPosY<SIZE)
      aPosY++;
  }
}

WASM_EXPORT
void nextMove() {
  //avance();
  //blanche, elle tourne de 90° vers la droite, change la couleur de la case en noir
  if (IMAGE[aPosY][aPosX] == blanc) {
    turnRight();
    IMAGE[aPosY][aPosX] = noir;
    avance();
  }
  //Si sur noir, tourne de 90° gauche, change la couleur de la case en blanc
  if (IMAGE[aPosY][aPosX] == noir) {
    turnLeft();
    IMAGE[aPosY][aPosX] = blanc;
    avance();
  }
}

WASM_EXPORT
void fill_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = blanc;
    }
  }
  aPosX = SIZE/2;
  aPosY = SIZE/2;
  direction = 0;
}

WASM_EXPORT
int getX() {
  return aPosX;
}

WASM_EXPORT
int getY() {
  return aPosY;
}