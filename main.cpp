#define WASM_EXPORT __attribute__((visibility("default")))


class CPoint{
public:
  int x;
  int y;
public:
  CPoint():
  x(0),
  y(0){

  }
  CPoint(int _x, int _y):
  x(_x),
  y(_y)
  {}
};

WASM_EXPORT
int main(){
  CPoint p(8,8);
  return p.x;
}