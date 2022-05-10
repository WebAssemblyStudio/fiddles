#define WASM_EXPORT __attribute__((visibility("default")))
const int SIZE = 256;
unsigned char PIC[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;

int xFourmi = 0;
int yFourmi = 0;
int orientation = 0;

WASM_EXPORT
int getDirection() {
  return orientation;
}


WASM_EXPORT
int getXPos() {
  return xFourmi;
}

WASM_EXPORT
int getYPos() {
  return yFourmi;
}

WASM_EXPORT
void* get_offset() {
  return &PIC;
}

WASM_EXPORT
int get_size() {
  return SIZE;
}

WASM_EXPORT
void init_pic() {
  for(int i=0; i<SIZE; i++) {
    for(int j=0; i<SIZE; i++) { 
      PIC[i][j][R] = 256;
      PIC[i][j][G] = 256;
      PIC[i][j][B] = 256;
      PIC[i][j][A] = 256; 
    }
  }
}

WASM_EXPORT
void move() {
  int newColor = PIC[xFourmi][yFourmi][R] == 0 ? 256 : 0;
  orientation = newColor == 0 ? 
    (orientation + 1) % 3 :
    (orientation + 2) % 3;

    PIC[xFourmi][yFourmi][R] = newColor;
    PIC[xFourmi][yFourmi][G] = newColor;
    PIC[xFourmi][yFourmi][B] = newColor;
    PIC[xFourmi][yFourmi][A] = newColor;

    switch(orientation) {
      case 0:
        yFourmi++;
        break;
      case 1:
        xFourmi++;
        break;
      case 2:
        yFourmi--;
        break;
      case 3:
        xFourmi--;
        break;
    } 
}


WASM_EXPORT
int main() {
  return 42;
}
