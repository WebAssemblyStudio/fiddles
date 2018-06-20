#include <iostream>
using namespace std;

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(int x) {
  std::cout << "X";
  return 42 + x;
}