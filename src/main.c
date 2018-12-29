#include <stdint.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern int64_t geti64_fromjs();

WASM_EXPORT
int main(void) {
  int64_t val = geti64_fromjs();
  return (val == 64);
}


