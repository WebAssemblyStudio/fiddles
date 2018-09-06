#include <stdint.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT _Bool test() {
  int32_t val = -1;
  uint64_t res = (uint64_t)val;
  return res == 0xffffffffffffffff;
}
