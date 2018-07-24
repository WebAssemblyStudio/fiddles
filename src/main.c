#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(n) {
 return n*2*3*4*5;
}
