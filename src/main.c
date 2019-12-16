#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(int a) {
  if(a > 5){
    return 5;
  } 
  return 10;
}
