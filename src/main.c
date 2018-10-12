#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdint.h>

/**
 * Seeded PRNG using xoshiro256+ 1.0
 */

static inline uint64_t rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

static uint64_t s[4];

WASM_EXPORT
double next(void) {
	const uint64_t result_plus = s[0] + s[3];

	const uint64_t t = s[1] << 17;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = rotl(s[3], 45);

  return (result_plus >> 11) * (1. / (UINT64_C(1) << 53));
}

WASM_EXPORT
void seed(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h) {
  s[0] = (uint64_t)a << 32 | (uint64_t)b;
  s[1] = (uint64_t)c << 32 | (uint64_t)d;
  s[2] = (uint64_t)e << 32 | (uint64_t)f;
  s[3] = (uint64_t)g << 32 | (uint64_t)h;
}