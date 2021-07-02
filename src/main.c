#include <mmap.h>
#include <stdio.h>
#include <sys/uio.h>
#include <unistd.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

void Function(int a, char *b) { sprintf(b, "A value [%d]", a); }
int main(void) {
  int i;
  char buff[1024];
  for (i = 0; i < 10; i++) {
    memset(buff, 0x00, 1024);
    Function(i, buff);
    printf("%s/n", buff);
  }
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
