#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdlib.h>

WASM_EXPORT
int fact(int n) {
  int v = 1;
  while (n > 0) {
    v *= n;
    n--;
  }
  return v;
}

int *arr;

WASM_EXPORT
int get(int x) {
  return arr[x];
}

WASM_EXPORT
int main() {
  arr = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }
  return fact(5);
}
