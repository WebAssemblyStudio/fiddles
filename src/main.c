#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256
unsigned int IMAGE[SIZE][SIZE];
unsigned int x = 128;
unsigned int y = 128;

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
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = rgb(0,0,0);
    }
  }
}

WASM_EXPORT 
void* move() { 
  if (IMAGE[x][y]==rgb(0,0,0)) { 
    IMAGE[x][y]=rgb(255,255,255); 
    x++; 
  } 
}

