#include <stdio.h>
#include <intrin.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

int test_fn(int a, int b)
{
  return a + b;
}

WASM_EXPORT
int main(void) {
  printf("%d\n", test_fn(50, 30));
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
