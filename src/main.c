#define WASM_EXPORT __attribute__((visibility("default"))) extern "C"

using func = int();


WASM_EXPORT
int main() {
  return 42;
}
WASM_EXPORT func functions[1] = {main};

WASM_EXPORT int x(int i) {
  return functions[i]();
}
