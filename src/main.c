#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int GCD(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

WASM_EXPORT
int GCD_rec(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD_rec(b, a % b);
}
