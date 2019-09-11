#define WASM_EXPORT __attribute__((visibility("default")))

#include <math.h>

WASM_EXPORT
int main() {
  return pow(4.0, 1.0);
}
