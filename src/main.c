#include <stdio.h>
#include <sys/uio.h>
#include <time.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern double number(int i);

extern double runJsLoop();

extern long unixTime();

int object[1];

WASM_EXPORT
void wasm2js() {
  double sum = 0.0;
  for (int i = 0; i < 50*1000*1000; i++) {
    sum += number(i);
  }
  printf("%d\n", sum);
}

WASM_EXPORT
void wasm() {
  double sum = 0.0;
  for (int i = 0; i < 50*1000*1000; i++) {
    sum += object[0] * i;
  }
  printf("%d\n", sum);
}

double numberWasm(int i) {
  return object[0] * i;
}

WASM_EXPORT
void wasm2wasm() {
  double sum = 0.0;
  for (int i = 0; i < 50*1000*1000; i++) {
    sum += numberWasm(i);
  }
  printf("%d\n", sum);
}

WASM_EXPORT
void js() {
  double sum = runJsLoop();
  printf("%d\n", sum);
}

WASM_EXPORT
void js2js() {
  double sum = runJs2JsLoop();
  printf("%d\n", sum);
}

void measure(char* name, void (*function)()) {
  printf("--- warmup %s ---\n", name);
  long start, end;
  for (int i = 0; i < 3; ++i) {
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
  printf("--- end %s ---\n\n\n", name);
}

WASM_EXPORT
int main(void) {
  object[0] = 1;

  measure("wasm2js", wasm2js);
  measure("wasm", wasm);
  measure("wasm2wasm", wasm2wasm);
  measure("js", js);
  measure("js2js", js2js);
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
