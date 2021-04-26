#include <stdlib.h>
#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct {
  double x, y;
} Vec2;

typedef struct {
  double x, y, z;
} Vec3;

WASM_EXPORT
Vec2* vec2(double x, double y) {
  Vec2* vec = malloc(sizeof(Vec2));

  vec->x = x;
  vec->y = y;

  return vec;
}

extern double add_js(double a, double b);

WASM_EXPORT
Vec3* vec3(double x, double y, double z) {
  Vec3* vec = malloc(sizeof(Vec3));

  vec->x = x;
  vec->y = y;
  vec->z = add_js(z, y);

  return vec;
}
