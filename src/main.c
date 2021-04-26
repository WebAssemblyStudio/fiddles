#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct {
    float x,y;
} Vec2;

WASM_EXPORT
Vec2 vec2(float x, float y) {
  Vec2 vec;
  vec.x = x;
  vec.y = y;

  return vec;
}
