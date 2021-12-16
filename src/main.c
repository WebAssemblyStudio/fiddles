#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  printf("Hello World\n");
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

WASM_EXPORT
int test(void) {
  char* str = "test\n";

  int i = 0;
  while(str[i] != '\0') {
    putc_js(str[i]);
    ++i;
  }

  return 0;
}

WASM_EXPORT
int read_file(void) {
  printf("read_file\n");

  FILE *fp;
  char fname[] = "temp";
  int chr, err;

  printf("fopen\n");
  fp = fopen(fname, "r");
  if(NULL == fp) {
    printf("%s file not open!\n", fname);
    return -1;
  }

  printf("errno:%d\n", errno);
  size_t sz = ftell(fp);
  printf("size:%ld\n", sz);
  printf("errno:%s\n", strerror(errno));
  fseek(fp, 0L, SEEK_END);
  sz = ftell(fp);
  printf("size:%ld\n", sz);

  // while(1) {
  //   if(ferror(fp)) {
  //     printf("エラーが発生しました");
  //     break;
  //   }
  //   chr = fgetc(fp);
  //   if(!feof(fp)) {
  //     printf("%c\n", chr);
  //   } else {
  //     break;
  //   }
  //   // putc_js(chr);
  // }

  printf("fclose\n");
  fclose(fp);

  return 0;
}

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
