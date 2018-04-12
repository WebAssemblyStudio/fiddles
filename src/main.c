#define WASM_EXPORT __attribute__((visibility("default")))

int hello(int a, int b){
  return a+b;
}

WASM_EXPORT
int main() {
  int aa = 1;
  int bb = 2;
  return hello(aa, bb);
}
