#define WASM_EXPORT __attribute__((visibility("default")))
#include <time.h>

WASM_EXPORT
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}