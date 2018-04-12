#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))


WASM_EXPORT
bool contains3(int numbers[3]) {
  for (int i = 0; i < 3; i++)
    if (numbers[i] == 3)
      return true;
  return false;
}


WASM_EXPORT
int main() {
  int numbers[3] = {1, 2, 3};
  printf("contains3: %d\n", contains3(numbers));
}

/* External function that is implemented in JavaScript. */
extern putc_js(char c);

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