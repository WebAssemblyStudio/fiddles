#define WASM_EXPORT __attribute__((visibility("default")))

#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

WASM_EXPORT
unsigned long max()
{
	return USHRT_MAX;
}

WASM_EXPORT
unsigned long prime(const unsigned long n)
{
	unsigned long asqrt;
	unsigned long p, i;
	unsigned long primes = 0;

	for (i = 2; i <= n; ++i)
	{
		asqrt = sqrt(i);
		bool prime = true;

		for (p = 2; p <= asqrt; ++p)
		{
			if (i % p == 0)
			{
				prime = false;
				break;
			}
		}

		if (prime)
			++primes;
	}

	return primes;
}

WASM_EXPORT
unsigned long eratosthenes(const unsigned long n)
{
	const unsigned long sqrtn = sqrt(n);
	unsigned long p, i;
	unsigned long primes = 0;

	//bool *prime = new bool[n + 1];
  bool *prime = malloc((n + 1) * sizeof(bool));

	for (p = 0; p <= n; ++p)
		prime[p] = true;

	for (p = 2; p <= sqrtn; ++p)
	{
		if (prime[p])
		{
#pragma omp parallel for
			for (i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (p = 2; p <= n; ++p)
		if (prime[p])
			++primes;

	//delete[] prime;
  free(prime);
  
  return primes;
}
