#define WASM_EXPORT __attribute__((visibility("default")))
#include <iostream>
WASM_EXPORT
int main() {
  for(;;)
  {
  std::cout<<"CHwdp";
  }
  return 42;
}
