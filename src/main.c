#include <stdlib.h>
#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct {
  float x,y;
} Vec2;

WASM_EXPORT
Vec2* vec2(int x, int y) {
  Vec2* vec = malloc(sizeof(Vec2));
  vec->x = x;
  vec->y = y;

  return vec;
}
