#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
int factorial(int n){
  if(n==0){
    return 1;
  }else{
    return n*factorial(n-1);
  }
}
