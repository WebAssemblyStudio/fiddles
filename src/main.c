#define WASM_EXPORT __attribute__((visibility("default")))

#include <iostream>

WASM_EXPORT
int main() {

  for (int i = 0; i < 5; i++) {
    cout << "123213";
  }

  return 42;
}
