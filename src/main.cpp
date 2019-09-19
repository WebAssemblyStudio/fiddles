typedef float r32;
struct v2f { r32 x, y; };
v2f operator+ (v2f a, v2f b) { return {a.x+b.x, a.y+b.y}; }
v2f operator- (v2f a, v2f b) { return {a.x-b.x, a.y-b.y}; }
v2f operator* (r32 f, v2f b) { return {f * b.x, f * b.y}; }
v2f operator* (v2f a, v2f b) { return {a.x*b.x, a.y*b.y}; }
v2f operator/ (v2f a, v2f b) { return {a.x/b.x, a.y/b.y}; }
struct Ray { v2f pos, dir; r32 length; };
struct Aabb { v2f min, max; };
struct Rigid_Body { v2f pos; Aabb aabb; };

struct RayIntersection {
  r32 t;   // ray coordinate at intersection
  v2f hit; // the point where the ray hits the AABB
  v2f fix; // A point on the edge or outside the AABB 
};

static RayIntersection
ray_aabb_intersection_point(Ray r, Rigid_Body rb)
{
    v2f aabbMin = rb.aabb.min + rb.pos;
    v2f aabbMax = rb.aabb.max + rb.pos;

    // these three lines might be un-necessarily dense.
    // {t1,t2} is basically a 4-vector of t-values which represent
    // the ray-coordinates of the intercepts of the 4 sides of the AABB.
    #define v_intercept(p) (((p) - r.pos) / r.dir)
    v2f t1 = v_intercept(aabbMin);
    v2f t2 = v_intercept(aabbMax);

    v2f end = r.pos + r.dir, fix;
    float t = 2;
    // BETWEEN is defined this way because we're not sure which of a and b is larger.
    // this part is branch-heavy partly because we're setting the fix-position in each case.
    #define BETWEEN(x, a, b) (((x) < (a)) != ((x) < (b)))
    if (BETWEEN(t1.x, t1.y, t2.y) && t1.x < t) { t = t1.x; fix = {aabbMin.x, end.y}; }
    if (BETWEEN(t2.x, t1.y, t2.y) && t2.x < t) { t = t2.x; fix = {aabbMax.x, end.y}; }
    if (BETWEEN(t1.y, t1.x, t2.x) && t1.y < t) { t = t1.y; fix = {end.x, aabbMin.y}; }
    if (BETWEEN(t2.y, t1.x, t2.x) && t2.y < t) { t = t2.y; fix = {end.x, aabbMax.y}; }
    
    if (t < 0 || t > 1) t = 0;
    return RayIntersection {t, r.pos + t * r.dir, fix};
}   

extern "C" void drawRect(r32 x1, r32 y1, r32 x2, r32 y2);
extern "C" void drawRay(r32 x1, r32 y1, r32 x2, r32 y2);
extern "C" void drawFix(r32 x1, r32 y1, r32 x2, r32 y2);
extern "C" void drawPoint(r32 x, r32 y, r32 fillStyle);
// projection to convert our world space pt to canvas space.
v2f proj(v2f pt) { return pt * v2f {200, -200} + v2f {300, 200}; }

#define WASM_EXPORT __attribute__((visibility("default")))
WASM_EXPORT
int main() { 
  Rigid_Body body { {0, 0}, {{-0.5, -0.2}, {0.5, 0.3}}};
  body.pos = {0, 0};
  Ray rays[] = {
    {{-1, 0}, {0.4, 0}},
    {{-1, 0.1}, {0.7, 0.1}},
    {{1, -0.3}, {-1, 0.7}},
    {{0.9, 0.8}, {-1.0, -0.8}},
    {{0.8, -0.1}, {-1.0, -0.8}},
    {{0.2, -0.9}, {-0.1, 1.8}},
  };
  // Draw AABB
  v2f min = proj(body.pos + body.aabb.min);
  v2f max = proj(body.pos + body.aabb.max);
  drawRect(min.x, min.y, max.x, max.y);

  for(int i=0; i<sizeof(rays) / sizeof(Ray); i++) { 
    auto ray = rays[i];
    auto pos = proj(ray.pos);
    auto end = proj(ray.pos + ray.dir);
    drawRay(pos.x, pos.y, end.x, end.y);
  
    auto intersection = ray_aabb_intersection_point(rays[i], body);
    if (!intersection.t) continue;
    
    auto pp = proj(intersection.hit);
    drawPoint(pp.x, pp.y, 0);

    auto q0 = proj(end);
    auto q1 = proj(intersection.fix);
    drawFix(q0.x, q0.y, q1.x, q1.y);
  }
}