#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

#include <iostream>
using namespace std;

int main() {
  cout << "Hello World, saluda a MAriano GREÑUDO " << endl;
  return 0;
  
}
