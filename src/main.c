#define WASM_EXPORT __attribute__((visibility("default")))


WASM_EXPORT
int nn(int n) {
  if(n == 1){
    return 1;
  }else{
    return n * nn(n-1);
  }
}

WASM_EXPORT
int main() {
  return nn(6);
}
