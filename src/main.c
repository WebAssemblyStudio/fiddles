#define WASM_EXPORT __attribute__((visibility("default")))

int is_prime(int number) {
  for (int divisor = 2; divisor < number; divisor++) {
    if (number % divisor == 0) {
      return 0;
    }
  }
  return 1;
}

WASM_EXPORT void find_primes(int *buffer, int length) {
  int tested_number = 2;
  int primes_found = 0;
  while (primes_found < length) {
    if (is_prime(tested_number)) {
      buffer[primes_found] = tested_number;
      primes_found++;
    }
    tested_number++;
  }
}
