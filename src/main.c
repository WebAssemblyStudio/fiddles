#include <stdio.h>
#include <sys/uio.h>
#include <unistd.h>

#define WASM_EXPORT __attribute__((visibility("default")))
#define PATHNAME_SIZE 1024

WASM_EXPORT
int main() {
  
    char pathname[PATHNAME_SIZE];
    getcwd(pathname, PATHNAME_SIZE);  
  printf("path: %s", pathname);
  printf("Hello World\n");
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