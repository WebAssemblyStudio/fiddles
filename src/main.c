#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int a = 0;
  a = f(0);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  a += f(2);
  return a;
}

int f(int b){
  return b*2;
}