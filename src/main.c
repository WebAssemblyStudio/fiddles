#define WASM_EXPORT __attribute__((visibility("default")))
#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <math.h>

WASM_EXPORT
int getRandomNumber(int min, int max) {
  return (rand() * (min - max) + max);
}

WASM_EXPORT
float degreeToRadians(int angle) {
  return  (angle * (M_PI / 180));
}
