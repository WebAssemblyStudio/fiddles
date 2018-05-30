#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

void putc_js(char c);
void getc_js();

WASM_EXPORT
int main(void) {
  printf("Starting\n");
  char c = getc_js() || 1;
  printf("Hello World\n");
  putc_js(c);
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);
extern void getc_js();


/* Basic implementation of the readv sys call. */ 
/*
WASM_EXPORT
size_t readv_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      //getc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  return cnt;
}
*/

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
