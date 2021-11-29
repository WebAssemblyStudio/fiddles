#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
#include <iostream>
int main() {
  char c = 'A';
  cout << c & 2 << endl;
  cout << c & 4 << endl;
}
