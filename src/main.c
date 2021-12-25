#include <stdio.h>
#include <sys/uio.h>
#include <stdbool.h>
#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

void check_prime(int n){
  int limit = (int)ceil(sqrt((double) n));
  for(int i=2; i<limit; i++) { 
    if(n%i == 0){
      printf("%u is composite: %u x %u\n", n, i, n/i); return;
    }
  }
  printf("%u is prime!\n", n); return;
}

WASM_EXPORT
int main(void) {
  check_prime(86697);
  check_prime(86737);
  printf("6697 x 86737 is %u\n", 86697 * 86737); // 3224870393
  check_prime(86697 * 86737);
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
