#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
}

extern int __heap_base;
extern int __data_end;

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
int Add(int a, int b) {
  return a + b;
}

WASM_EXPORT
int HeapBase() {
  //int* data = (int*)alloca(size);
  return __heap_base;
}
WASM_EXPORT
int DateEnd() {
  //int* data = (int*)alloca(size);
  return __data_end;
}

WASM_EXPORT
char* Get() {
  return "somestring";
}