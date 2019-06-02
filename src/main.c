// 
#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256

#define WHITE 0xffffffff
#define BLACK 0xff000000
#define DIR_N 0
#define DIR_E 1
#define DIR_S 2
#define DIR_W 3

unsigned int WORLD[SIZE][SIZE];

unsigned int ANT_X = SIZE/2;
unsigned int ANT_Y = SIZE/2;
unsigned int ANT_D = DIR_N;
unsigned int ITER = 0;


WASM_EXPORT
void* get_image_offset() {
  return (void *)WORLD;
}

WASM_EXPORT
int get_image_size() {
  return SIZE;
}

WASM_EXPORT
void init_world() {
  for (int i=0; i<SIZE; i++) {
    for (int j=0; j<SIZE; j++) {
      WORLD[i][j] = BLACK;
    }
  }
}

WASM_EXPORT
unsigned int step_world() {
  if (WORLD[ANT_X][ANT_Y] == WHITE) {
    WORLD[ANT_X][ANT_Y] = BLACK;
    ANT_D = (ANT_D + 1) % 4;
  } else {
    WORLD[ANT_X][ANT_Y] = WHITE;
    ANT_D = (ANT_D - 1 + 4) % 4;
  }
  switch (ANT_D) {
    case DIR_N:
      ANT_Y = (ANT_Y - 1 + SIZE) % SIZE;
      break;
    case DIR_E:
      ANT_X = (ANT_X - 1 + SIZE) % SIZE;
      break;
    case DIR_S:
      ANT_Y = (ANT_Y +1) % SIZE;
      break;
    case DIR_W:
      ANT_X = (ANT_X +1) % SIZE;
      break;
  }
  ITER += 1;
  return ITER;
}

WASM_EXPORT
unsigned int get_ant_x() {
  return ANT_X;
}

WASM_EXPORT
unsigned int get_ant_y() {
  return ANT_Y;
}

WASM_EXPORT
unsigned int get_ant_d() {
  return ANT_D;
}
