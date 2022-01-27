#include <vector.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
int getBufferSize(std::vector<uint8_t> buf){
  return buf.size();
}