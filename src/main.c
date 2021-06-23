#define WASM_EXPORT __attribute__((visibility("default")))

const unsigned WIDTH = 500;
const unsigned HEIGHT = 500;

int ScreenOffsetX = 0;
int ScreenOffsetY = 0;

unsigned int drawingColor = 0xffffffff;

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

void putPixel(int x, int y){
  if(!(x-ScreenOffsetX > WIDTH || x-ScreenOffsetX < 0 || y-ScreenOffsetY > HEIGHT || y-ScreenOffsetY < 0)){
    SCREEN_BUFFER[(y-ScreenOffsetY)*WIDTH+x-ScreenOffsetX] = drawingColor;
  }
}

void rect(int x, int y, int width, int height){
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){
      putPixel(x+i, y+j);
    }
  }
}

WASM_EXPORT
void update(){
  putPixel(10, 10, 0xffffffff);
}