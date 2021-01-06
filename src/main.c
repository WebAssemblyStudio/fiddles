#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
