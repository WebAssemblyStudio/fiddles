#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256
unsigned int IMAGE[SIZE][SIZE];

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
void fill_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = rgb(255,255,255);
    }
  }
}

enum directions{North, East, South, West};

WASM_EXPORT
void next_move() {
  static enum directions direction = East;
  static unsigned int x = SIZE/2;
  static unsigned int y = SIZE/2;

  // case blanche
  if(IMAGE[x][y] == rgb(255,255,255)) {
    IMAGE[x][y] = rgb(0,0,0);
    if(direction == East) {
      direction = South;
      x += 1;
    }
    else if(direction == South) {
      direction = West;
      y -= 1;
    }
    else if(direction == West) {
      direction = North;
      x -= 1;
    }
    else if(direction == North) {
      direction = East;
      y += 1;
    }
  }

  // case noire
  if(IMAGE[x][y] == rgb(0,0,0)) {
    IMAGE[x][y] = rgb(255,255,255);
    if(direction == East) {
      direction = North;
      x -= 1;
    }
    else if(direction == South) {
      direction = East;
      y += 1;
    }
    else if(direction == West) {
      direction = South;
      x += 1;
    }
    else if(direction == North) {
      direction = West;
      y -= 1;
    }
  }
}
