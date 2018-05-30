#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  char c = getchar() || 1;
  printf("hello world");
  putchar(c);
}
