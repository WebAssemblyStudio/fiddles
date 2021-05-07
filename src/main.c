#define WASM_EXPORT __attribute__((visibility("default")))

#include <time.h>
WASM_EXPORT
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}


//https://github.com/tsoding/prime-benchmark/blob/master/prime.c
#include <stdio.h>
#include <stdlib.h>
#define N (10 * 1000 * 1000)

WASM_EXPORT
int is_prime(int x)
{
  int primes[N] = {2};
  for (size_t i = 0; primes[i] * primes[i] <= x; ++i) {
      if (x % primes[i] == 0) {
          return 0;
      }
  }
  return 1;
}