#include <stdio.h>
#include <sys/uio.h>
#include <stdlib.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  char *ary; //declare the array pointer
int size = 12; //lets make it a size of 12 (12 slots)

//allocate the memory for the array
ary = (char*)calloc(size, sizeof(char));

//use the array
ary[0] = 'H';
ary[1] = 'e';
ary[2] = 'l';
ary[3] = 'l';
ary[4] = 'o';
ary[5] = ' ';
ary[6] = 'w';
ary[7] = 'o';
ary[8] = 'r';
ary[9] = 'l';
ary[10] = 'd';
ary[11] = '\n';

for (int i = 0; i < size; i++) {
  putchar(ary[i]);
}

//free the memory associated with the dynamic array
free(ary);

//and you can re allocate some more memory and do it again
//maybe this time double the size?
//ary = (int*)calloc(size * 2, sizeof(int));
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
