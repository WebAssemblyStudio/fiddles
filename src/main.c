#define WASM_EXPORT __attribute__((visibility("default")))
#define SIZE 256
#include <stdio.h>

unsigned int IMAGE[SIZE][SIZE];// 0 = black, 255 = black
unsigned int GRID[SIZE][SIZE];// 0 = black, 1 = black
char direction;
int positionX;
int positionY;
int iteration;

WASM_EXPORT
void* get_image() {
  return (void*)IMAGE;
}

WASM_EXPORT
unsigned int get_size() {
  return SIZE;
}

WASM_EXPORT
int get_iteration() {
  return iteration;
}

unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 256*g + 256*256*b + 0xff000000;
}

WASM_EXPORT
void* fill_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      unsigned int color = GRID[i][j];
      IMAGE[i][j] = rgb(
        255 * color,
        255 * color,
        255 * color
      );
    }
  }
}


WASM_EXPORT
void init(){  
  //fill white
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      GRID[i][j]=1;
    }
  }
  //set at center
  positionX =(int) SIZE/2;
  positionY =(int) SIZE/2;
  //face North
  direction = 'N'; 
  iteration= 0;
}

WASM_EXPORT
void move(){
  //turn direction
  unsigned int color = GRID[positionX][positionY];
  switch(direction){
    case 'N':if(color==0){direction='E';}else{direction='W';};
      break;
    case 'S':if(color==0){direction='W';}else{direction='E';};
      break;
    case 'E':if(color==0){direction='S';}else{direction='N';};
      break;
    case 'W':if(color==0){direction='N';}else{direction='S';};
      break;
   }

  //test out of bounds
  switch(direction){
    case 'N':if(positionX - 1 >=0){positionX-=1;}else{positionX=SIZE-1;};
      break;
    case 'S':if(positionX + 1 < SIZE){positionX+=1;}else{positionX=0;};
      break;
    case 'E':if(positionY + 1 < SIZE){positionY+=1;}else{positionY=0;};
      break;
    case 'W':if(positionY - 1 >= 0){positionY-=1;}else{positionY=SIZE-1;};
      break;
  }

  //update color of case
  if(GRID[positionX][positionY]==0)
    GRID[positionX][positionY]=1;
  else
    GRID[positionX][positionY]=0;

  iteration++; 
}
