#include <stdint.h>

#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct test {
  int64_t x;
  int64_t y;
} test;

WASM_EXPORT
test foo() {
  test test1;
  test1.x = 1;
  test1.y = 2;
  return test1;
}

WASM_EXPORT
int main() {
  return foo().x;
}
