#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
char* helloStr(){
  return "Paket Phoenix";
}

WASM_EXPORT
float squarer(float x){
  return x*x;
}

WASM_EXPORT
double rootsq(double num){
  return sqrt(num);
}
