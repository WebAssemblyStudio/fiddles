#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int resAdd = add(10, 20);
  int resSub = sub(resAdd, 20);
  return resSub;
}

WASM_EXPORT
int add(int a, int b){
  return a + b;
}

WASM_EXPORT
int sub(int a, int b){
  return a - b;
}