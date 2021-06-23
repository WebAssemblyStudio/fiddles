#define WASM_EXPORT __attribute__((visibility("default")))

const unsigned WIDTH = 500;
const unsigned HEIGHT = 500;

int ScreenOffsetX = 0;
int ScreenOffsetY = 0;

WASM_EXPORT
unsigned int SCREEN_BUFFER[WIDTH * HEIGHT];

WASM_EXPORT
unsigned int getScreenWidth(){
  return WIDTH;
}

WASM_EXPORT
unsigned int getScreenHeight(){
  return HEIGHT;
}

void update(){

}