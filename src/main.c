typedef float r32;
r32 square(r32 f) { return f * f; }
r32 min(r32 a, r32 b) { return a < b ? a : b; }
r32 max(r32 a, r32 b) { return a > b ? a : b; }

struct v2f { r32 x, y; };
v2f operator+ (v2f a, v2f b) { return {a.x+b.x, a.y+b.y}; }
v2f operator- (v2f a, v2f b) { return {a.x-b.x, a.y-b.y}; }
v2f operator* (v2f a, v2f b) { return {a.x*b.x, a.y*b.y}; }
v2f operator/ (v2f a, v2f b) { return {a.x/b.x, a.y/b.y}; }
v2f hadamard(v2f a, v2f b) { return a * b; }
r32 lengthSq(v2f v) { return v.x * v.x + v.y * v.y; }
v2f minimum(v2f a, v2f b) { return {min(a.x, b.x), min(a.y, b.y)}; }
v2f maximum(v2f a, v2f b) { return {max(a.x, b.x), max(a.y, b.y)}; }

struct Ray { v2f pos, dir; r32 length; };
struct Aabb { v2f min, max; };
struct Rigid_Body { v2f pos; Aabb aabb; };


extern "C" void drawRect(r32 x1, r32 y1, r32 x2, r32 y2);
extern "C" void drawRay(r32 x1, r32 y1, r32 x2, r32 y2);
v2f proj(v2f pt) { return pt * v2f {400, -400} + v2f {400, 400}; }
void drawRect(v2f min, v2f max) { 
  min = proj(min);
  max = proj(max);
  drawRect(min.x, min.y, max.x, max.y);
}
void drawRay(Ray r) { 
  auto pos = proj(r.pos);
  auto end = proj(r.pos + r.dir);
  drawRay(pos.x, pos.y, end.x, end.y);
}


static v2f
ray_aabb_intersection_point(Ray r, Rigid_Body rb)
{
    v2f result = {};
    
    v2f invRayDir = {
        1.f / r.dir.x,
        1.f / r.dir.y
    };
    
    v2f aabbMin = rb.aabb.min + rb.pos;
    v2f aabbMax = rb.aabb.max + rb.pos;
    
    v2f t1 = hadamard(aabbMin - r.pos, invRayDir);
    v2f t2 = hadamard(aabbMax - r.pos, invRayDir);
    
    v2f tMaxVec = maximum(t1, t2);
    v2f tMinVec = minimum(t1, t2);
    
    r32 tMin = max(tMinVec.x, tMinVec.y);
    r32 tMax = min(tMaxVec.x, tMaxVec.y);
    
    if(tMin < tMax)
    {
        result = {tMin, tMax};
    }
    
    return result;
}

struct Ray_Trace_Result { 
   bool intersected;
   v2f normal;
   float penDepth;
};
static Ray_Trace_Result
ray_aabb_test(Ray r, Rigid_Body rb)
{
    Ray_Trace_Result result = {};
    
    v2f tMinMax =  ray_aabb_intersection_point(r, rb);
    if(tMinMax.x != 0 && 
       tMinMax.y != 0)
    {
        v2f intPoint = {
            r.pos.x + (tMinMax.x * r.dir.x),
            (r.pos.y + (tMinMax.y * r.dir.y))
        };
        
        if(lengthSq(r.pos - intPoint) > square(r.length))
        {
            return result;
        }
        
        r32 xDepth = intPoint.x - (r.pos.x + r.dir.x);
        r32 yDepth = intPoint.y - (r.pos.y + r.dir.y);
        
        result.intersected = 1;
        if(xDepth > yDepth)
        {
            result.penDepth = xDepth;
            if(tMinMax.x < 0.f)
            {
                result.normal = v2f{1.f, 0.f};
            }
            else
            {
                result.normal = v2f{-1.f,  0.f};
            }
        }
        else
        {
            result.penDepth = yDepth;
            if(tMinMax.y < 0.f)
            {
                result.normal = v2f{0.f, -1.f};
            }
            else
            {
                result.normal = v2f{0.f, 1.f};
            }
        }
    }
    
    return result;
}

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() { 
  Rigid_Body body { {0, 0}, {{-0.5, -0.2}, {0.5, 0.3}}};
  Ray rays[] = {
    {{-1, 0}, {0.5, 0}},
    {{-1, 0.1}, {0.7, 0.1}},
  };
  drawRect(body.pos + body.aabb.min, body.pos = body.aabb.max);
  for(int i=0; i<sizeof(rays) / sizeof(Ray); i++) { 
    drawRay(rays[i]); 
  }
}