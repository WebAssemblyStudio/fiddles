/**
* DEVELOPPED BY
* - IDOUX Etienne 11923599
* - SABARD Pierre 11913234
**/

#define WASM_EXPORT __attribute__((visibility("default")))
// Canvas size macro, lenght & height is the same
#define _SIZE 200

// Image representation (arrays)
unsigned int image[_SIZE][_SIZE]; // Image for view
unsigned int grid[_SIZE][_SIZE]; // grid, content image color for each pixel (white or black)
// Ant information 
int posX; // ant x position
int posY; // ant y position
char dir; // ant direction (Up, Right, Bottom, Left)
int it;   // Number of iteration for our algorithm

// GETTERS
WASM_EXPORT
unsigned int getSize() {
  return _SIZE;
}

WASM_EXPORT
void* getImage() {
  return (void*) image;
}

WASM_EXPORT
int getIteration(){
  return it;
}

unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 256*g + 256*256*b + 0xff000000;
}


// Init image & ant infos
WASM_EXPORT
void init() {
  // Set ant at the center, change direction to up & init iterations to 0
  posX = (int) _SIZE/2;
  posY = (int) _SIZE/2;
  dir = 'U';
  it = 0;
  // Fill grid with white to init image afterwards
  for (int i=0; i < _SIZE; i++) {
    for (int j=0; j < _SIZE; j++) {
      grid[i][j] = 1;
    }
  }
}

// Fill image from grid values
WASM_EXPORT
void fillImage(){
  for (int i=0; i < _SIZE; i++) {
    for (int j=0; j < _SIZE; j++) {
      unsigned int gridColor = grid[i][j];
      image[i][j] = rgb(255*gridColor, 255*gridColor, 255*gridColor);
    }
  }
}

// Do one iteration : move ant & change grid
// Langton's ant algorithm :
// If color = black, turn left, change actual color to white & move forward
// If color = white, turn right, change actual color to black & move forward
WASM_EXPORT
void doIteration(){
  // Check color for next move
  unsigned int actualColor = grid[posX][posY];
  switch(dir){
    case 'U':
      dir = actualColor == 0 ? 'R' : 'L';
      break;
    case 'B':
      dir = actualColor == 0 ? 'L' : 'R';
      break;
    case 'R':
      dir = actualColor == 0 ? 'B' : 'U';
      break;
    case 'L':
      dir = actualColor == 0 ? 'U' : 'B';
      break;
  }

  // Check if we are out of bounds
  switch(dir){
    case 'U':
      posX = posX - 1 >= 0 ? posX-1 : _SIZE-1;
      break;
    case 'B':
      posX = posX + 1 < _SIZE ? posX+1 : 0;
      break;
    case 'R':
      posY = posY + 1 < _SIZE ? posY+1 : 0;
      break;
    case 'L':
      posY = posY - 1 >= 0 ? posY-1 : _SIZE-1;
      break;
  }

  // Update our grid
  grid[posX][posY] = grid[posX][posY] == 0 ? 1 : 0;

  // iteration is done, adding to sum
  it++;
}
