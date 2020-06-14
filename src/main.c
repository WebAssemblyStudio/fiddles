#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256
unsigned int IMAGE[SIZE][SIZE];
unsigned int xAnt;
unsigned int yAnt;
unsigned int directionAnt;
// 1 : N
// 2 : E
// 3 : S
// 4 : W

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
void* initImage() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = rgb(
        255,
        255,
        255
      );
    }
  }

  xAnt = SIZE/2;
  yAnt = SIZE/2;
  directionAnt = 1;
}

WASM_EXPORT
void makeOneStep() {
  if(IMAGE[xAnt][yAnt] == rgb(255,255,255)) {
    IMAGE[xAnt][yAnt] = rgb(0,0,0);
    directionAnt = (directionAnt - 1) % 4;
  } else {
    IMAGE[xAnt][yAnt] = rgb(255,255,255);
    directionAnt = (directionAnt + 1) % 4;
  }

  if (directionAnt == 0) {
    directionAnt = 4;
  }

  switch(directionAnt) {
    case 1 :
      yAnt = yAnt - 1;
      break;
    case 2 :
      xAnt = xAnt + 1;
      break;
    case 3 :
      yAnt = yAnt + 1;
      break;
    case 4 :
      xAnt = xAnt - 1;
      break;
  }
}


