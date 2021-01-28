#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT int add(int x, int y) {
  return x+y;
}

int isPrime(number) {
	if (number < 2) return 0;
	for (int i = 2; i < number; i++)
		if (number%i == 0) return 0;

	return 1;  
}

WASM_EXPORT int getLastPrime(int number) {
	int lastPrime = 2;
	for (int i = 2; i <= number; i++) {
		if (isPrime(i))
			lastPrime = i;
	}
	return lastPrime;
}
