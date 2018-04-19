#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void debug();


/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
int add(int * res, int fd, int x) {
  const int e = fd + x;
   *res = e;
   debug();
    return 0;
}

WASM_EXPORT
int add_two(int fd) {
  int res;
  add(&res, fd, 2);
  return res;
}