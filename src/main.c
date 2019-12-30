#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  int a = 889;
  int b = 0;
  switch (a){
    case 777:
      b = a + 3;
      break;
    case 888:
      printf("888\n");
      break;
    default:
      printf("default!!\n");
  }

  char str[20] = "donki ho-te";
  printf("%s\n", str);

  // printf関数では最後に改行コードを入れないと下のOutputに文字が出力されない。


  // printf("%d\n", b);
  printf("Hello World\n");
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
