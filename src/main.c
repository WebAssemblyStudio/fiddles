#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
extern int (*chain_method_bind(int, int))();

WASM_EXPORT
int main() {
    int (*f)(int, int) = chain_method_bind(1, 2);
    return f(10, 2);
}

