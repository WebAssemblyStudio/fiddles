#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdio.h>

const int f = 'f'-'b';
const int i = f/f;
const int z = f>>i;
const int buz = f*i*z;

const char fizzbuzz[] = {
    'f','i','z','z',
    'b','u','z','z',
};
const char fizz[] = {
    (f+i)*(z/z)+(buz<<z),
    (f*i+z)*buz-z,
    ((f+i)<<z/z)+buz*z*z,
    (f+i+z)*buz*z-(f+i+z)+buz+z,
    f*i*z-buz
};
const char buzz[] = {
    (f+i)*(z/z)+(buz<<z),
    (f+i)*z*(buz+z),
    f/i+z*z+(buz>>z),
    f*i*z-buz
};

WASM_EXPORT
int main() {
    for (int fizbuz=f*i*z/buz; fizbuz<=f*i*z+buz; fizbuz+=f*i*z/buz) {
        printf(
            printf(fizbuz%(-(f+i)*z/z+buz) ? fizz+buz/z : fizz, buz/z, &fizzbuzz[(f>>i>>z)*buz])
            |
            printf(fizbuz%((f*i>>z)+buz/z) ? f+i-z+buzz : fizz, buz/z, &fizzbuzz[f*i*z-buz/z])
            ?
            f*i/z+buzz : (f>>i>>z)+buzz, fizbuz);
    }
    return ~((f|i|z)-buz);
}