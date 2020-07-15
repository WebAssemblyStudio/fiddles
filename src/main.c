#define WASM_EXPORT __attribute__((visibility("default")))
#include <iostream.h>
WASM_EXPORT
int main() {
  std::cout << "Hellow World" << std::endl;
  
  return 42;
}
