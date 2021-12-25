#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  sieve(1000);
  printf("Hello World\n");
}

void sieve(int n){
  printf("yo ");
  int size = (int)ceil(sqrt((double) n));
  BOOL prime[size] = {true};
  for(int i=0; i<size; i++) {
    for(int j=1; j<size; j+=i){
      prime[j] = false;
    }
  }
  for(int i=0; i<size; i++){
    if(prime[i] && n%i == 0){
      return printf("%d is composite: %d x %d\n", n, i, n/i);
    }
  }
  return printf("%d is prime!\n")
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
