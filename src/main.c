#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int arraytest[5] = {0,1,2,3,4};

WASM_EXPORT
int main() {
  return arraytest[2];
}
