#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <time.h>

#define WASM_EXPORT __attribute__((visibility("default")))

int seed=-1;

WASM_EXPORT
void * walloc(int size) {
  return malloc(size);
}

WASM_EXPORT
void wfree(void *p) {
  free(p);
}

WASM_EXPORT
void fillbox(unsigned long *buf,int width,int height,int color){
  if (seed == -1) {
    seed = time(NULL);
    srand(seed);
  }
  for (int y=0;y<height;y++){
    int pos = y*width;
    for (int x=0;x<width;x++){
      buf[pos+x] = 0xff000000 | color; // Alfa channel = 1.0
    }
  }
}

WASM_EXPORT
void fillrandomrect(unsigned long *buf,int width,int height){
  int sx = rand() % width;
  int sy = rand() % height;
  int ex = rand() % (width-sx) + 1; 
  int ey = rand() % (height-sy) + 1;
  int c1 = rand() % 0x100;
  int c2 = rand() % 0x100;
  int c3 = rand() % 0x100;
  int color = c1<<16 | c2<<8 | c3;

  int alpha =  (rand() % 0x100) << 24;

  for (int y=sy;y<ey;y++){
    int pos = y*width;
    for (int x=sx;x<ey;x++){
      buf[pos+x] = alpha | color; // Alfa channel = 1.0
    }
  }

}

WASM_EXPORT
int main() {
//  printf("Hello World\n");
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      putc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  return cnt;
}