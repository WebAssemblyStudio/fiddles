#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int fib(int n) 
{ 
    if (n <= 1) 
        return n; 
    return fib(n-1) + fib(n-2); 
} 
