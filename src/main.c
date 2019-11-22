#define WASM_EXPORT __attribute__((visibility("default")))
#define HEIGHT 400
#define WIDTH 800

int data[WIDTH * HEIGHT];
int red = (255 << 24) | 255;

WASM_EXPORT
int main() {
  return 42;
}


WASM_EXPORT
int* render() {
   for (int y = 0; y < HEIGHT; y++) {
     int yw = y * WIDTH;
     for (int x = 0; x < WIDTH; x++) {
       data[yw + x] = red;
     }
   }
   return &data[0];
}

