#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
void reverse(unsigned char* p, int len) {
    p[2] = 174;
}