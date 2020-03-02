#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>

extern void consoleLog(float num);

WASM_EXPORT
float getSqrt(float num) {
  consoleLog(123);
  return sqrt(num);
}