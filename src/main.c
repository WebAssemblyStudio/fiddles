#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int getBiggestPrime(int less_then) {
  int prime_nums[less_then];
  prime_nums[0] = 2;
  int count_of_prime = 1;
  for (int num = 3; num <= less_then; num+=2) {
    int add = 1;
    for (int i = 0; i < less_then; i++) {
      if (prime_nums[i] != 0) {
        if (num % prime_nums[i] == 0) {
          add = 0;
          break;
        }
      }
    }
    if (add == 1) {
      prime_nums[count_of_prime] = num;
      count_of_prime++;
    }
  }
  
  return prime_nums[count_of_prime-1];
}