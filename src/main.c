#include <stdio.h>
#include <sys/uio.h>
#include <time.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern double number(int i);

extern long unixTime();

WASM_EXPORT
void wasm2js() {
  double sum = 0.0;
  for (int i = 0; i < 100*1000*1000; i++) {
    sum += number(i);
  }
  printf("%d\n", sum);
}

WASM_EXPORT
void wasm() {
  double sum = 0.0;
  for (int i = 0; i < 100*1000*1000; i++) {
    sum += i * i;
  }
  printf("%d\n", sum);
}

void measure(char* name, void (*function)()) {
  printf("--- warmup %s ---\n", name);
  long start, end;
  for (int i = 0; i < 5; ++i) {
    start = unixTime();
    (*function)();
    end = unixTime();
    printf(" --> iteration %d, time = %d\n", i, end - start);
  }
  printf("--- measure %s ---\n", name);
  start = unixTime();
  (*function)();
  end = unixTime();
  printf("time = %d\n", end - start);
  printf("--- end %s ---\n", name);
}

WASM_EXPORT
int main(void) {
  // measure("wasm2js", wasm2js);
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
