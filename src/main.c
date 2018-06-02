#define WASM_EXPORT __attribute__((visibility("default")))
#include <iostream>

using namespace std;

WASM_EXPORT
int main() {
  for(int i = 0;i < 10;i++){
    cout << i << endl;
  }
}
