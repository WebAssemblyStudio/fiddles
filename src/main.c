#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  printf("Hello World\n");
  fprintf(stderr, "Error World\n");
}

/* External function that is implemented in JavaScript. */
extern void putcs_js(int fd, const void* c, int len);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    const struct iovec *v = iov + i;
    putcs_js(fd, v->iov_base, v->iov_len);
    cnt += v->iov_len;
  }
  return cnt;
}
