#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct vec2 {
  float x, y;
} vec2;

typedef struct dot {
  vec2 p, v, a;
  float d;
  int c;
} dot;

#define MAX_DOT_COUNT 4096
#define INITIAL_DOT_COUNT (1024)
#define INITIAL_RADIUS (32.0f)
#define INITIAL_REPEL (240.0f / 10000.0f)
#define INITIAL_ALIGN (120.0f / 10000.0f)
#define INITIAL_ATTRACT (60.0f / 10000.0f)
#define INITIAL_LOWER_THRESHOLD (20.0f / 100.0f)
#define INITIAL_HIGHER_THRESHOLD (75.0f / 100.0f)
#define INITIAL_MAX_VEL (300.0f / 100.0f)
#define INITIAL_MIN_VEL (2.0f / 100.0f)
#define INITIAL_CENTER_PULL (1.0f / 10000.0f)
#define INITIAL_MAX_DISTANCE (32.0f)

const int TWO_PI = M_PI * 2;
const int PALLETE[] = {
    0xffbdd6f6, 0xff8aa3c3, 0xff777599, 0xff716281,
    0xff5f494e, 0xff4f3920, 0xff3f2a0f, 0xff1e1408,
};

int DOT_COUNT;
float RADIUS;
float RADIUS2;
float REPEL;
float ALIGN;
float ATTRACT;
float LOWER_THRESHOLD;
float HIGHER_THRESHOLD;
float THRESHOLD_DELTA;
float MAX_VEL;
float MAX_VEL2;
float MIN_VEL;
float MIN_VEL2;
float CENTER_PULL;
float MAX_DISTANCE;
float MAX_DISTANCE2;
float TIMESTAMP;

int data[128 * 128 * 4];
dot dots[MAX_DOT_COUNT];
vec2 center;

#define min(a, b) (a > b ? b : a)

#define max(a, b) (a > b ? a : b)

#define clamp(a, low, high) min(max(a, low), high)

#define random(min, max) (env_random() * (max - min) + min)

extern float env_random();

inline float length2(vec2 *v) { return v->x * v->x + v->y * v->y; }

inline float length(vec2 *v) { return sqrtf(length2(v)); }

inline float dist2(vec2 *v, vec2 *d) {
  float dx = d->x - v->x;
  float dy = d->y - v->y;
  return dx * dx + dy * dy;
}

inline float dist(vec2 *v, vec2 *d) { return sqrtf(dist2(v, d)); }

void add(vec2 *v, vec2 *a) {
  v->x += a->x;
  v->y += a->y;
}

void sub(vec2 *v, vec2 *s) {
  v->x -= s->x;
  v->y -= s->y;
}

void scale(vec2 *v, float f) {
  v->x *= f;
  v->y *= f;
}

void normalize(vec2 *v) {
  float len = length(v);
  if (len > 0) {
    scale(v, 1 / len);
  }
}

void init_dots(int start, int end) {
  for (int i = start; i < end; i++) {
    dot *d = &dots[i];
    add(&d->p, &(vec2){random(0, 128), random(0, 128)});
    add(&d->v, &(vec2){random(0, 1), random(0, 1)});
    normalize(&d->v);
    scale(&d->a, 0);
    d->d = random(.8, .99);
    d->c = random(2, 5);
  }
}

WASM_EXPORT
void config(int count, int radius, float repel, float align, float attract,
            float lower_threshold, float higher_threshold, float max_vel,
            float min_vel, float center_pull, float max_distance) {
  count = clamp(count, 0, MAX_DOT_COUNT);
  init_dots(DOT_COUNT, count);
  DOT_COUNT = count;
  RADIUS = radius;
  RADIUS2 = radius * radius;
  REPEL = repel;
  ALIGN = align;
  ATTRACT = attract;
  LOWER_THRESHOLD = lower_threshold;
  HIGHER_THRESHOLD = higher_threshold;
  THRESHOLD_DELTA = higher_threshold - lower_threshold;
  MAX_VEL = max_vel;
  MAX_VEL2 = max_vel * max_vel;
  MIN_VEL = min_vel;
  MIN_VEL2 = min_vel * min_vel;
  CENTER_PULL = center_pull;
  MAX_DISTANCE = max_distance;
  MAX_DISTANCE2 = max_distance * max_distance;
}

WASM_EXPORT
int *init(int width, int height) {
  config(INITIAL_DOT_COUNT, INITIAL_RADIUS, INITIAL_REPEL, INITIAL_ALIGN,
         INITIAL_ATTRACT, INITIAL_LOWER_THRESHOLD, INITIAL_HIGHER_THRESHOLD,
         INITIAL_MAX_VEL, INITIAL_MIN_VEL, INITIAL_CENTER_PULL,
         INITIAL_MAX_DISTANCE);
  center = (vec2){width / 2, height / 2};
  init_dots(0, DOT_COUNT);
  return &data[0];
}

WASM_EXPORT
void update(float timestamp) {
  float delta = timestamp - TIMESTAMP;
  float step = delta / (1000 / 24);
  TIMESTAMP = timestamp;

  for (int i = 0; i < DOT_COUNT; i++) {
    for (int j = i + 1; j < DOT_COUNT; j++) {
      dot *a = &dots[i];
      dot *b = &dots[j];
      vec2 dir = a->p;
      sub(&dir, &b->p);
      float d2 = length2(&dir);
      if (d2 <= RADIUS2) {
        float p = d2 / RADIUS2;
        if (p < LOWER_THRESHOLD) {
          float f = (LOWER_THRESHOLD / p - 1) * REPEL;
          vec2 r = dir;
          normalize(&r);
          scale(&r, f);
          add(&a->a, &r);
          scale(&r, -1);
          add(&b->a, &r);
        } else if (p < HIGHER_THRESHOLD) {
          float P = (p - LOWER_THRESHOLD) / (THRESHOLD_DELTA);
          float f = (1 - (cosf(P * TWO_PI) * 0.5 + 0.5)) * ALIGN;
          vec2 r = b->v;
          normalize(&r);
          scale(&r, f);
          add(&a->a, &r);
          r = a->v;
          normalize(&r);
          scale(&r, f);
          add(&b->a, &r);
        } else {
          float P = (p - HIGHER_THRESHOLD) / (1 - p);
          float f = (1 - (cosf(P * TWO_PI) * -0.5 + 0.5)) * ATTRACT;
          vec2 r = dir;
          normalize(&r);
          scale(&r, f);
          add(&b->a, &r);
          scale(&r, -1);
          add(&a->a, &r);
        }
      }
    }
  }

  for (int i = 0; i < DOT_COUNT; i++) {
    dot *d = &dots[i];
    vec2 dir = d->p;
    sub(&dir, &center);
    float d2 = length2(&dir);
    if (d2 > MAX_DISTANCE2) {
      vec2 r = dir;
      normalize(&r);
      scale(&r, (d2 - MAX_DISTANCE2) * CENTER_PULL * -1);
      add(&d->a, &r);
    }

    scale(&d->a, step);
    add(&d->v, &d->a);
    float v2 = length2(&d->v);
    if (v2 > MAX_VEL2) {
      normalize(&d->v);
      scale(&d->v, MAX_VEL);
    } else if (v2 < MIN_VEL2) {
      normalize(&d->v);
      scale(&d->v, MIN_VEL);
    }

    vec2 v = d->v;
    scale(&v, step);
    add(&d->p, &v);
    scale(&d->v, d->d);
    scale(&d->a, 0);
  }
}

WASM_EXPORT
void draw(int width, int height) {
  for (int i = 0; i < DOT_COUNT; i++) {
    dot *d = &dots[i];
    int x = d->p.x;
    int y = d->p.y;
    if (x >= 0 && x < width && y >= 0 && y < height) {
      data[y * width + x] = PALLETE[d->c];
    }
  }
}