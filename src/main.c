#include <stdio.h>
#include <stdint.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct Rect {
  uint32_t     x; // 4
  uint32_t     y; // 4
  uint16_t  width; // 2
  uint16_t  height; // 2
  uint16_t  rotation; // 2
} Rect;

const int SIZE = 64;
WASM_EXPORT
int data[SIZE];

WASM_EXPORT
int* getData() {
  return &data[0];
}

WASM_EXPORT
int main() {
  printf("--------------\nHello World\n");
}

WASM_EXPORT
void test() {
  Rect *object = (Rect *) data;
  printf("x: %d\n",object->x);
  printf("y: %d\n",object->y);
  printf("width: %d\n",object->width);
  printf("height: %d\n",object->height);
  printf("rotation: %d\n",object->rotation);
  object->width = 500;
}

/* External function that is implemented in JavaScript. */
extern int putc_js(char c);

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