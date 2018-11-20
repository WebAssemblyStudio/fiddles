#define WASM_EXPORT __attribute__((visibility("default")))
#include <fiostream.h>  

WASM_EXPORT
int main() {
  return 42;
}
