#include <stdio.h>
#include <sys/uio.h>
#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))


WASM_EXPORT
double pow(){
    double base = 2, power = 20;
    double  result = pow(base,power);
    return pow(base,power);
}