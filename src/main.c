#define WASM_EXPORT __attribute__((visibility("default")))

#include <math.h>

const unsigned WIDTH = 300;
const unsigned HEIGHT = 300;

int ScreenOffsetX = 0;
int ScreenOffsetY = 0;

unsigned int drawingColor = 0xffffffff;

WASM_EXPORT
unsigned int SCREEN_BUFFER[WIDTH * HEIGHT];
unsigned int CLEARED_SCREEN_BUFFER[WIDTH * HEIGHT];

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

void clearScreen(){
  for(int i = 0; i < WIDTH*HEIGHT; i++){
    putPixel((i%WIDTH)+ScreenOffsetX, floor(i/WIDTH)+ScreenOffsetY);
  }
}

int x = 0;

WASM_EXPORT
void update(){
  // clear screen
  drawingColor = 0xff000000;
  clearScreen();

  drawingColor = 0xffffffff;
  rect(x, 0, 32, 32);
  // x++;
  ScreenOffsetX--;
}