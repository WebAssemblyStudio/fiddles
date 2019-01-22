#include <string.h>
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 666;
}

WASM_EXPORT
int add (int x, int y) {
  return x + y;
}

WASM_EXPORT
int square (int x) {
  return x * x;
}

WASM_EXPORT
char* test(){
  return "aaa";
}