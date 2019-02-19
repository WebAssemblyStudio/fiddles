#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct vec2 {
  double x, y;
} vec2;

typedef struct dot {
  vec2 p, v, a;
  double d;
  int c;
} dot;

#define DOT_COUNT 2000
#define RADIUS 64
#define REPEL .00005
#define ALIGN .004
#define ATTRACT 0.005
#define LOWER_THRESHOLD 0.2
#define HIGHER_THRESHOLD 0.6
#define CENTER_PULL 0.00005
#define MAX_VEL 4
#define MIN_VEL 1

const int TWO_PI = M_PI * 2;
const int RADIUS_2 = RADIUS * RADIUS;
const int MAX_DISTANCE2 = 80 * 80;
const int MAX_VEL2 = MAX_VEL * MAX_VEL;
const int MIN_VEL2 = MIN_VEL * MIN_VEL;

int data[400 * 300 * 4];

int pallete[] = {
    0xffbdd6f6, 0xff8aa3c3, 0xff777599, 0xff716281,
    0xff5f494e, 0xff4f3920, 0xff3f2a0f, 0xff1e1408,
};

dot dots[DOT_COUNT];
vec2 center;

#define random(min, max) (env_random() * (max - min) + min)

extern double env_random();

inline double length2(vec2* v) { return v->x * v->x + v->y * v->y; }

inline double length(vec2* v) { return sqrt(length2(v)); }

inline double dist2(vec2* v, vec2* d) {
  double dx = d->x - v->x;
  double dy = d->y - v->y;
  return dx * dx + dy * dy;
}

inline double dist(vec2* v, vec2* d) { return sqrt(dist2(v, d)); }

void add(vec2* v, vec2* a) { v->x += a->x; v->y += a->y; }

void sub(vec2* v, vec2* s) { v->x -= s->x; v->y -= s->y; }

void scale(vec2* v, double f) { v->x *= f; v->y *= f; }

void normalize(vec2* v) {
  double len = length(v);
  if (len > 0) {
    scale(v, 1 / len);
  }
}

WASM_EXPORT
int *init(int width, int height) {
  for (int i = 0; i < DOT_COUNT; i++) {
    dot* d = &dots[i];
    add(&d->p, &(vec2){random(0, width), random(0, height)});
    add(&d->v, &(vec2){random(0, 1), random(0, 1)});
    normalize(&d->v);
    scale(&d->a, 0);
    d->d = random(.6, .99);
    d->c = (int)(random(2, 5));
  }

  center = (vec2) { width / 2, height / 2 };

  return &data[0];
}

WASM_EXPORT
void update(int timestamp) {
  for (int i = 0; i < DOT_COUNT; i++) {
    for (int j = i + 1; j < DOT_COUNT; j++) {
      dot* a = &dots[i];
      dot* b = &dots[j];
      vec2 dir = a->p;
      sub(&dir, &b->p);
      double d2 = length2(&dir);
      if (d2 <= RADIUS_2) {
        double p = d2 / RADIUS_2;
        if (p < LOWER_THRESHOLD) {
          double f = (LOWER_THRESHOLD / p - 1) * REPEL;
          vec2 r = dir;
          normalize(&r);
          scale(&r, f);
          add(&a->a, &r);
          scale(&r, -1);
          add(&b->a, &r);
        } else if (p < HIGHER_THRESHOLD) {
          double P = (p - LOWER_THRESHOLD) / (HIGHER_THRESHOLD - LOWER_THRESHOLD);
          double f = (1 - (cos(P * TWO_PI) * 0.5 + 0.5)) * ALIGN;
          vec2 r = b->v;
          normalize(&r);
          scale(&r, f);
          add(&a->a, &r);
          r = a->v;
          normalize(&r);
          scale(&r, f);
          add(&b->a, &r);
        } else {
          double P = (p - HIGHER_THRESHOLD) / (1 - p);
          double f = (1 - (cos(P * TWO_PI) * -0.5 + 0.5)) * ATTRACT;
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
    dot* d = &dots[i];
    vec2 dir = d->p;
    sub(&dir, &center);
    double d2 = length2(&dir);
    if (d2 > MAX_DISTANCE2) {
      vec2 r = dir;
      normalize(&r);
      scale(&r, (d2 - MAX_DISTANCE2) * CENTER_PULL * -1);
      add(&d->a, &r);
    }

    add(&d->v, &d->a);
    double v2 = length2(&d->v);
    if (v2 > MAX_VEL2) {
      normalize(&d->v);
      scale(&d->v, MAX_VEL);
    } else if (v2 < MIN_VEL2) {
      normalize(&d->v);
      scale(&d->v, MIN_VEL);
    }

    scale(&d->v, d->d);
    add(&d->p, &d->v);
    scale(&d->a, 0);
  }
}

WASM_EXPORT
void draw(int width, int height) {
  for (int i = 0; i < DOT_COUNT; i++) {
    dot* d = &dots[i];
    int x = (int)d->p.x;
    int y = (int)d->p.y;
    if (x >= 0 && x <= width && y >= 0 && y <= height) {
      data[y * width + x] = pallete[d->c];
    }    
  }
}