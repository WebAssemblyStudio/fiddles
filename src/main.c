#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int square (int x) {
　　　　　　　　return x * x;
　　　　　　}
