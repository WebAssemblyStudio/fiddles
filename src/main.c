#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>


WASM_EXPORT
double power(double number,double power_value) {
  return pow(number,power_value);
}

WASM_EXPORT
char* helloWorld(){
  return "hello world";
}