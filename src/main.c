#include<unistd.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  char c = 'b';
  write(1, &c, 1);
}

/* External function that is implemented in JavaScript. */
extern putc_js(char c);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, void *buf, size_t size) {
  char c = ((char)buf)[0];  
  putc_js(c);
  return 1;
}