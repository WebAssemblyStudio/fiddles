#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;

int x_orign;
int y_orign;

int dir;

int ANTUP = 0;
int ANTRIGHT = 1;
int ANTDOWN = 2;
int ANTLEFT = 3;

WASM_EXPORT
void* get_offset() {
  return &BUFFER;
}

WASM_EXPORT
int get_size() {
  return SIZE;
}

void turnRight()
{
    dir++;
    if (dir > ANTLEFT)
    {
        dir = ANTUP;
    }
}

void turnLeft()
{
    dir--;
    if (dir < ANTUP)
    {
        dir = ANTLEFT;
    }
}

void moveForward()
{
    if (dir == ANTUP)
    {
        y_orign--;
    }
    else if (dir == ANTRIGHT)
    {
        x_orign++;
    }
    else if (dir == ANTDOWN)
    {
        y_orign++;
    }
    else if (dir == ANTLEFT)
    {
        x_orign--;
    }

    if (x_orign > SIZE - 1)
    {
        x_orign = 0;
    }
    else if (x_orign < 0)
    {
        x_orign = SIZE - 1;
    }

    if (y_orign > SIZE - 1)
    {
        y_orign = 0;
    }
    else if (y_orign < 0)
    {
        y_orign = SIZE - 1;
    }
}


WASM_EXPORT
// Génère une image dans BUFFER
void fill() {
    x_orign = SIZE / 2;
    y_orign = SIZE / 2;
    dir = ANTUP;

  for (int y=0; y<SIZE; y++) {
    for (int x=0; x<SIZE; x++) {
      BUFFER[y][x][3] = 255;
    }
  }

    int state = BUFFER[x_orign][y_orign][3];

    if (state == 0)
    {
        turnRight();
        BUFFER[x_orign][y_orign][3] = 1;
        moveForward();
    }
    else if (state == 1)
    {
        turnLeft();
        BUFFER[x_orign][y_orign][3] = 1; 
        moveForward();
    }
}

WASM_EXPORT
void go(i) {
  BUFFER[i][50][3] = 100; 
}