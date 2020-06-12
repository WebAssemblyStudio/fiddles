#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE  300

unsigned int IMAGE[SIZE][SIZE]; // y / x

int x = SIZE / 2;
int y = SIZE / 2;
int direction = 0; // 0 up, 1 right, 2 down, 3 left

struct pos  {
  int x;
  int y;
};
unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 256*g + 256*256*b + 0xff000000;
}
 
WASM_EXPORT
void* get_image() {
  return (void*)IMAGE;
}

WASM_EXPORT
unsigned int get_size() {
  return SIZE;
}

WASM_EXPORT
unsigned int getX() {
   return x;
}

WASM_EXPORT
unsigned int getD() {
  return direction;
}
WASM_EXPORT
unsigned int getY() {
  return y;
}

WASM_EXPORT
unsigned int gg() {
  return IMAGE[y][x];
}

WASM_EXPORT
unsigned int d2() {
  return rgb(0,0,0);
}

WASM_EXPORT
unsigned int d() {
  return rgb(255,255,255);
}


WASM_EXPORT
unsigned int getT() {
  return 255 + 256*255 + 256*256*255 + 0xff000000;
} 
WASM_EXPORT
struct pos getPos(){
  struct pos p = {x,y};
  return p;
}


WASM_EXPORT
void* turnLeft(){
  if(direction == 0){
    direction = 3;
    x--;
  }
  if(direction == 1){
    direction = 0;
    y--;
  }
  if(direction == 2){
    direction = 1;
    x++;
  }
  if(direction == 3){
    direction = 2;
    y++;
  }
}
WASM_EXPORT
void* turnRight(){
  if(direction == 0){
    direction = 1;
    x++;
  }
  if(direction == 1){
    direction = 2;
    y++;
  }
  if(direction == 2){
    direction = 3;
    x--;
  }
  if(direction == 3){
    direction = 0;
    y--;
  }
}




WASM_EXPORT
void* fill_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = rgb(
        i*256/SIZE,
        j*256/SIZE,
        (SIZE-i)*256/SIZE
      );
    }
  }
}

int isWhite(struct pos pos){
  return IMAGE[pos.y][pos.x] ==  rgb(255,255,255); 
}

void* setWhite(struct pos pos){
  return IMAGE[pos.y][pos.x] = rgb(255,255,255); 
}

void* setBlack(struct pos pos){
  return IMAGE[pos.y][pos.x] = rgb(0,0,0); 
}

WASM_EXPORT
void* move() {
  struct pos pos = getPos();
  if(isWhite(pos)){
      setBlack(pos);
      turnRight();
  }else{
      setWhite(pos);
      turnLeft();
  }

}


WASM_EXPORT
void* init_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = rgb(
        255,
        255,
        255
      );
    }
  }
}

