#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>

int mod (int a, int b)
{
   if(b < 0) //you can check for b == 0 separately and do what you want
     return mod(a, -b);   
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

WASM_EXPORT
int little_fermat(number) {
  if (mod(pow(2, number), number) == 2) {
    return 1;
  } else {
    return 0;
  }
}

int isprime(number) {
  for (int a = 0; a < sqrt(number); a = a + 1) {

  }
}