#include <stdint.h>

#define WASM_EXPORT __attribute__((visibility("default")))

uint32_t x[5];

WASM_EXPORT
  uint32_t b() {
      uint64_t sum;
  sum = (uint64_t)2111111111UL * (uint64_t)x[3] +
     (uint64_t)1492 * (uint64_t)(x[2]) +
     (uint64_t)1776 * (uint64_t)(x[1]) +
     (uint64_t)5115 * (uint64_t)(x[0]) +
     (uint64_t)x[4];
  x[3] = x[2];  x[2] = x[1];  x[1] = x[0];
  x[4] = (uint32_t)(sum >> 32);                  // Carry
  x[0] = (uint32_t)sum;                          // Low 32 bits of sum
  return x[0];
  }
  
WASM_EXPORT
  uint32_t seed(uint32_t seed) {
    int i;
  uint32_t s = seed;
  for (i = 0; i < 5; i++) {
    s = s * 29943829 - 1;
    x[i] = s;
  }
  for (i=0; i<19; i++) b();
  }