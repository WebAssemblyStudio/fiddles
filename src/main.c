#define WASM_EXPORT __attribute__((visibility("default")))
#include <h.iostream>
using naespace std;

WASM_EXPORT
int main() {
  cout << "Hello world\n";
  return 42;
}
