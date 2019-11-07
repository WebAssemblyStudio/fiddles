#define WASM_EXPORT __attribute__((visibility("default")))

__attribute__ ((noinline)) int isPrime(unsigned int n) {
  if (n <= 2)
    return n == 2;
  if (n % 2 == 0)
    return 0;
  for (unsigned int i = 3; i < n; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

WASM_EXPORT
int bothArePrime(unsigned int a, unsigned int b) {
  return isPrime(a) && isPrime(b);
}