#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256
unsigned int IMAGE[SIZE][SIZE];
unsigned int x;
unsigned int y;
unsigned int deg = 0;

extern void console_log(int i);

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
void* start() {
  x = 100;
  y = 100;
  IMAGE[x][y] = rgb(255,255,255);
}
WASM_EXPORT
void* move() {
  if(IMAGE[x][y] == rgb(255,255,255)){
    deg -= 1;
    IMAGE[x][y] = rgb(0,0,0);
  }
  else if(IMAGE[x][y] == rgb(0,0,0)){
    deg += 1;
    IMAGE[x][y] = rgb(255,255,255);
  }
  if(deg == 0 || deg == 4 || deg == -4){
    x++;
    deg = 0;
  }
  if(deg == -1 || deg == 3){
    y++;
  }
  if(deg == -2 || deg == 2){
    x--;
  }
  if(deg == 1 || deg == -3){
    y--;
  }
  x = x % SIZE;
  y = y % SIZE;
}

WASM_EXPORT
void* fill_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = rgb(0,0,0);
    }
  }
}