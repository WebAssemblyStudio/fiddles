#define WASM_EXPORT __attribute__((visibility("default")))

extern int getSomeConstant();

__attribute__((noinline))
int isDivisibleBy(int value, int divisor) {
  return value % divisor == 0 ? 1 : 0;
}

extern int isDivisibleByExtern(int value, int divisor);

int isPrime(int num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (isDivisibleBy(num, i) == 1)
             return 0;
     }
     return 1;
}

WASM_EXPORT
int computeNthPrime(int n) {
  int val = 1;
  while (n > 0) {
    val++;
    if (isPrime(val) == 1) {
      n--;
    }    
  }

  return val;
}