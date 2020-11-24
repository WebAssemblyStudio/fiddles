#include <stdio.h>
#define WASM_EXPORT __attribute__((visibility("default")))

unsigned __int128 i128pow(int base, int exp)
{
    unsigned __int128 result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

WASM_EXPORT
int main() {
  return 0;
}

int rsa(int value, int key, int modulus){
  unsigned __int128 res = i128pow(value, key);
  res %= modulus;
  return res;
}

WASM_EXPORT
int encrypt(int value){
  return rsa(value, 31, 111);
}

WASM_EXPORT
int decrypt(int value){
  return rsa(value, 7, 111);
}