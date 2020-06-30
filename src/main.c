#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
char * title() {
    return "1 hey hahaha";
}

WASM_EXPORT
int main() {
    return 42;
}
