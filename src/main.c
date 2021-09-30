#define WASM_EXPORT __attribute__((visibility("default")))

struct Point {
  int a;
  int b;
};


WASM_EXPORT
int add() {
  struct Point p;
  p.a = 1;
  p.b = 2;

  return 0;
}
