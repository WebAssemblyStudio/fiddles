#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256
unsigned int IMAGE[SIZE][SIZE];

unsigned int ant_x = SIZE / 2;
unsigned int ant_y = SIZE / 2;

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

unsigned int ant_dir = RIGHT;

# define BLACK 0
# define WHITE 1

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

extern void console_log(int x, int y, int col, int dir);

WASM_EXPORT
void* init_image() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      IMAGE[i][j] = rgb(255, 255, 255);
    }
  }
  return 0;
}

WASM_EXPORT
void *update_image() {
  int col = IMAGE[ant_x][ant_y] == rgb(0, 0, 0) ? BLACK : WHITE;
  if (col == BLACK) {
    IMAGE[ant_x][ant_y] = rgb(255, 255, 255);
    ant_dir = (ant_dir + 1) % 4;
  } else {
    IMAGE[ant_x][ant_y] = rgb(0, 0, 0);
    ant_dir = (ant_dir + 3) % 4;
  }
  switch(ant_dir) {
    case RIGHT:
      ant_x = (ant_x + 1) % SIZE;
      break;
    case UP:
      ant_y = (ant_y + 1) % SIZE;
      break;
    case LEFT:
      ant_x = (ant_x - 1) % SIZE;
      break;
    default:
      ant_y = (ant_y - 1) % SIZE;
  }

  //console_log(ant_x, ant_y, col, ant_dir);
  return 0;
}
