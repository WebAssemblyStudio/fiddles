#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct {
  float x;
  float y;
  float z;
} vec3;

void vec3_add(vec3* target, vec3* v1, vec3* v2) {
  target->x = v1->x + v2->x;
  target->y = v1->y + v2->y;
  target->z = v1->z + v2->z;
}

void vec3_sub(vec3* target, vec3* v1, vec3* v2) {
  target->x = v1->x - v2->x;
  target->y = v1->y - v2->y;
  target->z = v1->z - v2->z;
}

void vec3_mul(vec3* target, vec3* v1, vec3* v2) {
  target->x = v1->x * v2->x;
  target->y = v1->y * v2->y;
  target->z = v1->z * v2->z;
}

void vec3_scale(vec3* target, vec3* v1, float scale) {
  target->x = v1->x * scale;
  target->y = v1->y * scale;
  target->z = v1->z * scale;
}

float vec3_length_sq(vec3* v) {
  return v->x * v->x + v->y * v->y + v->z * v->z;
}

float vec3_length(vec3 *v) {
  return sqrt(vec3_length_sq(v));
}

void vec3_normalize(vec3* target, vec3* v) {
  float inv_length = 1.0 / vec3_length(v);

  target->x = v->x * inv_length;
  target->y = v->y * inv_length;
  target->z = v->z * inv_length;
}

WASM_EXPORT
float main() {
  vec3 v1 = { 0.2, 0.4, 0.6 };
  vec3 v2 = { 0.2, 0.4, 0.6 };

  vec3_add(&v1, &v1, &v2);
  vec3_normalize(&v1, &v1);

  return vec3_length(&v1);
}
