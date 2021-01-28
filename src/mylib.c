#include <stdbool.h> 
#define WASM_EXPORT __attribute__((visibility("default")))

bool isPrime(int number) {
	if (number < 2) return false;
	for (int i = 2; i < number; i++)
		if (number%i == 0) return false;

	return true;  
}

WASM_EXPORT int getLastPrime(int number) {
	int lastPrime = 2;
	for (int i = 2; i <= number; i++) {
		if (isPrime(i))
			lastPrime = i;
	}
	return lastPrime;
}
