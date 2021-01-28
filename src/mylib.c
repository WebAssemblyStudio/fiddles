#include <stdbool.h> 
#define WASM_EXPORT __attribute__((visibility("default")))

bool isPrime(int number) {
	if (number < 2) return false;
	for (int i = 2; i < number; i++)
		if (number%i == 0) return false;

	return true;  
}

WASM_EXPORT int getSumPrime(int number) {
	int sumPrime = 0;
	for (int i = 2; i <= number; i++)
		if (isPrime(i)) sumPrime += i;

	return sumPrime;
}
