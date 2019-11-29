#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int fibonacci(int n) {
  int i, t, a = 0, b = 1;
  for (i = 0; i < n; i++) {
    t = a + b;
    a = b;
    b = t;
  }
  return b;
}

WASM_EXPORT
long factorial(int n)
{
  if(n<0) return 0;
  if (n == 0)
    return 1;
  else
    return(n * factorial(n-1));
}