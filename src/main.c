#include <stdio.h>

extern void js_log(int i);

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int logic() {
  for (int i = 0; i < 10; i++) {
    js_log(i);
  }
  return 0;
}
