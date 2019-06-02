// 
#define WASM_EXPORT __attribute__((visibility("default")))

#define MAX_SIZE 256

unsigned int IMAGE[SIZE][SIZE];

WASM_EXPORT
unsigned int get_size() {
  return SIZE;
}

WASM_EXPORT
void* fill_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+1) {
      IMAGE[i][j] = rgb(
        i*256/SIZE,
        j*256/SIZE,
        (SIZE-i)*256/SIZE,
      );
    }
  }
}

unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 256*g + 256*256*b + 0xff000000;
}

