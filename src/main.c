#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int mandelIter(cx, cy, maxIter){
  float x = 0.0;
  float y = 0.0;
  int xx = 0;
  int yy = 0;
  int xy = 0;
    
  int i = maxIter;
  while( i-- && xx + yy <= 4 ){
    xy = x * y;
    xx = x * x;
    yy = y * y;
    x = xx - yy + cx;
    y = xy + xy + cy;
  }
  return maxIter - i;
}