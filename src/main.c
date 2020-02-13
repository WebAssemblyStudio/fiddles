#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

struct AA {
  int a;
  int b;
};

#define ARRAY_SIZE(a)  sizeof(a)/sizeof(a[0])

extern int TT_test(void);

WASM_EXPORT
int main(void) {
  printf("Hello World\n");

  int index;
  struct AA a[10];

  for (index = 0; index < ARRAY_SIZE(a); index ++)
  {
    a[index].a = index;
    a[index].b = index * index;
  }

  for (index = 0; index < ARRAY_SIZE(a); index ++)
  {
    printf("%d => %d:%d\n", index, a[index].a, a[index].b);
  }

  TT_test();
  
  return 100;
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
