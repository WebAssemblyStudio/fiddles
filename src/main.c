#include <Windows.h>
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  AllocConsole();
  return 42;
}
