#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256
unsigned int IMAGE[SIZE][SIZE];
unsigned int COLORS[SIZE][SIZE];
unsigned int interval;
enum direction { NORD, SUD, EST, OUEST};

struct fourmie {
  unsigned int x;
  unsigned int y;
  enum direction dir;
};

struct fourmie f;

/*WASM_EXPORT
struct fourmie get_fourmie() {
  struct fourmie f;
  f.x = SIZE/2;
  f.y = SIZE/2;
  f.dir = SUD;
  return f;
}*/

WASM_EXPORT
unsigned int get_x() {
  return f.x;
}

WASM_EXPORT
unsigned int get_y() {
  return f.y;
}

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
void* fill_image() {
  for (int i=0; i<SIZE; i+=interval) {
    for (int j=0; j<SIZE; j+=interval) {
      int color = COLORS[i][j];
      IMAGE[i][j] = rgb(
        color,
        color,
        color
      );
      
    }
  }
}

WASM_EXPORT
void* init() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      COLORS[i][j] = 255;
    }
  }
  interval = 1;
  f.x = SIZE/2;
  f.y = SIZE/2;
  f.dir = NORD;
}

void change_dir() {
  if(f.dir == SUD) {
    if(COLORS[f.x][f.y] == 0) f.dir = EST;
    if(COLORS[f.x][f.y] == 255) f.dir = OUEST;
  }else if(f.dir == OUEST) {
    if(COLORS[f.x][f.y] == 0) f.dir = SUD;
    if(COLORS[f.x][f.y] == 255) f.dir = NORD;
  }else if(f.dir == NORD) {
    if(COLORS[f.x][f.y] == 0) f.dir = OUEST;
    if(COLORS[f.x][f.y] == 255) f.dir = EST;
  }else if(f.dir == EST) {
    if(COLORS[f.x][f.y] == 0) f.dir = NORD;
    if(COLORS[f.x][f.y] == 255) f.dir = SUD;
  }
}

void change_color() {
  if(COLORS[f.x][f.y] == 0){
    COLORS[f.x][f.y] = 255;
  } else if(COLORS[f.x][f.y] == 255) {
    COLORS[f.x][f.y] = 0;
  }
}

void avance_fourmie() {
  if(f.dir == SUD) {
    f.x = f.x + 1;
    if(f.x >= SIZE-1) f.x = 1;
  }else if(f.dir == OUEST) {
    f.y = f.y -1;
    if(f.y <= 0) f.y = SIZE-2;
  }else if(f.dir == NORD) {
    f.x = f.x -1;
    if(f.x <= 0) f.x = SIZE-2;
  }else if(f.dir == EST) {
    f.y = f.y + 1;
    if(f.y >= SIZE-1) f.y = 1;
  }
}

WASM_EXPORT
void* loop() {
  fill_image();
  change_dir();
  change_color();
  avance_fourmie();
  IMAGE[f.x][f.y] = rgb(255,0,0);
}