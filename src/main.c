#define WASM_EXPORT __attribute__((visibility("default")))

#define WIDTH 10
#define HEIGHT 10

int data[WIDTH * HEIGHT];
int red = (255 << 24) | 255;
int black = 0xFF000000;

int renderData[1000];

WASM_EXPORT
int fillRequestCount() {
  return 2;
}

int bx = 4;
int by = 4;

WASM_EXPORT
int* fillRequest() {
  // x/y
  renderData[0] = 0;
  renderData[1] = 0;
  // size
  renderData[2] = 10;
  renderData[3] = 10;
  // col (0xRRGGBB)
  renderData[4] = 0xFFFF00;

  // x/y
  bx += (rand() % 3) - 1;
  by += (rand() % 3) - 1;
  if (bx < 0) { bx = 0; }
  if (bx > 9) { bx = 9; }
  if (by < 0) { by = 0; }
  if (by > 9) { by = 9; }

  renderData[5] = bx;
  renderData[6] = by;

  // size
  renderData[7] = 2;
  renderData[8] = 2;
  // col (0xRRGGBB)
  renderData[9] = 0xFF1493;

  return &renderData[0];
}

WASM_EXPORT
int* renderDataPointer() {
  return &renderData[0];
}

WASM_EXPORT
int width() {
  return WIDTH;
}

WASM_EXPORT
int height() {
  return HEIGHT;
}

WASM_EXPORT
int* render() {
   for (int y = 0; y < HEIGHT; y++) {
     int yw = y * WIDTH;
     for (int x = 0; x < WIDTH; x++) {
       data[yw + x] = rand();
     }
   }

   data[11] = black;
   data[21] = black;
   data[31] = black;
   data[41] = black;
   data[51] = black;

   data[32] = black;
   data[33] = black;

   data[14] = black;
   data[24] = black;
   data[34] = black;
   data[44] = black;
   data[54] = black;

   data[16] = black;
   data[26] = black;
   data[36] = black;
   data[46] = black;
   data[56] = black;

   return &data[0];
}
