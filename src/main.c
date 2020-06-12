#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256
unsigned int IMAGE[SIZE][SIZE];
unsigned int IMAGE_COLOR[SIZE][SIZE]; // 0 black 1 white

WASM_EXPORT
void* get_image() {
  return (void*)IMAGE;
}

WASM_EXPORT
unsigned int get_size() {
  return SIZE;
}

unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 256*g + 256*256*b + 0xff000000;
}

typedef struct {
    int x;
    int y;
    int rotation;
} Spider;
Spider spider;

void spider_up() {
    if (spider.y > 1) {
        spider.y = spider.y - 1;
    }
}

void spider_down() {
    if (spider.y + 1 < SIZE) {
        spider.y ++;
    }
}

void spider_left() {
    if (spider.x > 1) {
        spider.x --;
    }
}

void spider_right() {
    if (spider.x + 1 < SIZE) {
        spider.x ++;
    }
}

void move() {
    if (spider.rotation == 0) {
        spider_right();
    }
    else if (spider.rotation == 90) {
        spider_up();
    }
    else if (spider.rotation == 180) {
        spider_left();
    } else {
        spider_down();
    }
}

WASM_EXPORT
void* fill_image() {
    spider.x = SIZE / 2;
    spider.y = SIZE / 2;
    spider.rotation = 180; // gauche
    for (int i=0; i<SIZE; i+=1) {
        for (int j=0; j<SIZE; j+=1) {
            IMAGE[i][j] = rgb(255,255,255);
            IMAGE_COLOR[i][j] = 1;
        }
    }
    IMAGE[spider.y][spider.x] = rgb(0,0,0);
    IMAGE_COLOR[spider.y][spider.x] = 0;
    return IMAGE;
}

WASM_EXPORT
void next_step() {

    if (IMAGE_COLOR[spider.y][spider.x] == 0) {
        spider.rotation = (spider.rotation + 90) % 360;
        IMAGE_COLOR[spider.y][spider.x] = 1;
        IMAGE[spider.y][spider.x] = rgb(255,255,255);
    } else {
        spider.rotation = spider.rotation - 90;
        if (spider.rotation < 0) {
            spider.rotation += 360;
        }
        IMAGE_COLOR[spider.y][spider.x] = 0;
        IMAGE[spider.y][spider.x] = rgb(0,0,0);
    }
    move();
}