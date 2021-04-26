#include <stdlib.h>
#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct {
  double x, y;
} Vec2;

WASM_EXPORT
Vec2* vec2(double x, double y) {
  Vec2* vec = malloc(sizeof(Vec2));

  vec->x = x;
  vec->y = y;

  return vec;
}
