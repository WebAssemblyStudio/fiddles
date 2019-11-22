#include <stdio.h>
#include <sys/uio.h>
#include <time.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern double number(int i);

void wasm2js() {
  double sum = 0.0;
  for (int i = 0; i < 10; i++) {
    sum += number(i);
  }
  printf("%d\n", sum);
}

void measure(char* name, void (*function)()) {
  printf("--- measure %s ---\n", name);
  clock_t start = clock();
  (*function)();
  clock_t end = clock();
  printf("--- end %s ---\n", name);
}

WASM_EXPORT
int main(void) {
  measure("wasm", wasm2js);
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
