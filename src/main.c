#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
   int x=1,y=2,sum,limit = 100;
    int evensum=2;             
    
    while( (x+y)<limit ) {
        sum=x+y;
        x=y;
        y=sum;
        if (sum%2==0)
            evensum+=sum;
    }
    printf("%d \n",evensum);
    return 0;
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