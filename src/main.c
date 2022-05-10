#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;
int orientationFourmi = 0; //0 haut, 1 bas, 2 droite, 3 gauche
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
    case 0: //haut
            posX++;
            orientationFourmi = 2;
          break;

    case 1: //bas
          posX--;
          orientationFourmi = 3;
          break;

    case 2: // droite
          posY--;
          orientationFourmi = 1;
          break;

    case 3: // gauche
          posY++;
          orientationFourmi = 0;
          break;

  }
}

void deplacementGauche(){
  switch (orientationFourmi){
    case 0: //haut
          posX--;
          orientationFourmi = 3;
          break;

    case 1: //bas
          posX++;
          orientationFourmi = 2;
          break;

    case 2: // droite
          posY++;
          orientationFourmi = 0;
          break;

    case 3: // gauche
          posY--;
          orientationFourmi = 1;
          break;
  }
}

WASM_EXPORT
void deplacementFourmi(){
  if(BUFFER[posX][posY][R] == 255){
    deplacementDroite();
    BUFFER[posX][posY][R] = 0;
    BUFFER[posX][posY][G] = 0;
    BUFFER[posX][posY][B] = 0;
  } else if(BUFFER[posX][posY][R] == 0){
    deplacementGauche();
    BUFFER[posX][posY][R] = 255;
    BUFFER[posX][posY][G] = 255;
    BUFFER[posX][posY][B] = 255;
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

  //int posX = rand() % SIZE;
  //int posY = rand() % SIZE;

  int posX = SIZE/2;
  int posY = SIZE/2;

  orientationFourmi = 0;
}

WASM_EXPORT
void boucle(){
  while(posX > 0 && posX < SIZE && posY > 0 && posY < SIZE){
    deplacementFourmi();
  }
}

