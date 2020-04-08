#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

#define PRECISION 0.001

float sinus(double x) {
  double result = x;  
  double a = x;
  double i = 3;
  do {
    a *= -x*x/((i-1)*i);
    result += a; 
    i += 2;   
  } while(a > PRECISION);
  return result;
}


WASM_EXPORT
int main(void) {
  char *buf = new char[200]; 
  sprintf(buf, "sinus %f", sinus(1));  
  printf(buf);
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
