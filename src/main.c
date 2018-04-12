#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int count = 0;
  for(count = 0; count < 100; count++){
    if(count % 15 == 0){
      printf("Fizz Buzz\n");
    }

    if(count % 3 == 0){
      printf("Fizz\n");
    }
    if(count % 5 == 0){
      printf("Buzz\n");
    }
    printf("%d\n", count + 1);
  }
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