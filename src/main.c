#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

/* External function that is implemented in JavaScript. */
extern void draw(int x1, int y1, int x2, int y2);

WASM_EXPORT
int add(void) {
  for (int i=0;i<100;i++) {
    draw(0,i,100,100);
  }
  return 42;
}

