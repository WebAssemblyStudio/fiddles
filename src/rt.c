#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

/* External function that is implemented in JavaScript. */
WASM_EXPORT int rt_add(int x, int y) { return x + y; }

/* External function that is implemented in JavaScript. */
WASM_EXPORT int rt_sin(float x) { return sin(x); }
