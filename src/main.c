#define WASM_EXPORT __attribute__((visibility("default")))
#define HEIGHT 400
#define WIDTH 800

int screenWidth;
int screenHeight;

void consoleLog (char* offset, int len);
void consoleLogNum (float num);

int data[WIDTH * HEIGHT];
int red = (255 << 24) | 255;

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
void init(int width, height){
    screenWidth = width;
    screenHeight = height;
}

WASM_EXPORT
int* nextFrame() {
   consoleLog("testing", 7);
   consoleLogNum(7);
   consoleLogNum(screenHeight);
   for (int y = 0; y < screenWidth; y++) {
     int yw = y * screenWidth;
     for (int x = 0; x < screenHeight; x++) {
       data[yw + x] = red;
     }
   }
   return &data[0];
}

