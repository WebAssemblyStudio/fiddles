#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 100;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;

int antX = 50;
int antY = 50;
unsigned char antDirection = 's';

WASM_EXPORT
void* get_offset() {
  return &BUFFER;
}

WASM_EXPORT
int get_size() {
  return SIZE;
}

WASM_EXPORT
void initialize() {

  for(int i=0; i<SIZE; i++) {
    for(int j=0; j<SIZE; j++) {
      BUFFER[i][j][R] = 255;
      BUFFER[i][j][G] = 255;
      BUFFER[i][j][B] = 255;
      BUFFER[i][j][A] = 255;
    }
  }
}

WASM_EXPORT
void turnRight() {
  if(antDirection == 's'){
    antDirection = 'w';
  }else if(antDirection == 'n'){
    antDirection = 'e';
  }else if(antDirection == 'e'){
    antDirection = 's';
  }else if(antDirection == 'w'){
    antDirection = 'n';
  }
}

WASM_EXPORT
void turnLeft() {
  if(antDirection == 'n'){
    antDirection = 'w';
  }else if(antDirection == 'w'){
    antDirection = 's';
  }else if(antDirection == 's'){
    antDirection = 'e';
  }else if(antDirection == 'e'){
    antDirection = 'n';
  }
}

WASM_EXPORT
void forward() {
  if(antDirection == 'n'){
    if(antY < SIZE -1)
      antY += 1;
  }else if(antDirection == 'e'){
    if(antX < SIZE -1)
      antX += 1;
  }else if(antDirection == 's'){
    if(antY > 0)
      antY -= 1;
  }else if(antDirection == 'w'){
    if(antY > 0)
      antX -= 1;
  }
}

WASM_EXPORT
void move() {
  if(BUFFER[antX][antY][R] == 255){
    turnLeft();
    BUFFER[antX][antY][R] = 0;
    BUFFER[antX][antY][G] = 0;
    BUFFER[antX][antY][B] = 0;
    BUFFER[antX][antY][A] = 255;
    forward();
  }else{
    turnRight();
    BUFFER[antX][antY][R] = 255;
    BUFFER[antX][antY][G] = 255;
    BUFFER[antX][antY][B] = 255;
    BUFFER[antX][antY][A] = 255;
    forward();
  }
}

WASM_EXPORT
int main() {
  return 42;
}
