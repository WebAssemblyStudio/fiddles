#include <cstdio>
#include <sys/uio.h>

#ifdef __cplusplus
#define WASM_EXPORT extern "C" __attribute__ ((visibility ("default"))) 
#define EXTERNC extern "C"
#else
#define WASM_EXPORT __attribute__ ((visibility ("default"))) 
#define EXTERNC extern
#endif

WASM_EXPORT
int main(void) {
  printf("Hello World\n");
}

WASM_EXPORT
int deref(int* ptr) {
  return *ptr;
}

WASM_EXPORT
int accumulate(int* begin, int len) {
  int result = 0;
  for (int i = 0; i < len; i++) {
    result += *(begin + i);
  }
  return result;
}

WASM_EXPORT
int _accumulate3(int* begin, int len) {
  int result = 0;
  for (int i = 0; i < len; i++) {
    result += *(begin + i);
  }
  return result;
}

/* External function that is implemented in JavaScript. */
EXTERNC void putc_js(char c);

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
