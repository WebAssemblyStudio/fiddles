#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return add(4,19);
}

int add(int a,int b){
  return a+b;
}
