#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  int height = 6;
  int maxLength = 7;
  char hash = '#';
  int blocks = 2;
  int spaces = 5;

  for (int row = 0; row < height; row++) {
    for (int spacesRow = 0; spacesRow < spaces; spacesRow++) {
      printf(" ");
    }
    for (int blocksRow = 0; blocksRow < blocks; blocksRow++) {
      printf("%c", hash);
    }
      printf("\n");

    if (blocks < maxLength) {
      blocks++;
      spaces--;
    }
  }
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

/* Basic implementation of the writev syscall. */ 
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
