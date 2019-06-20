#include <stdlib.h>
#include <time.h>
#define WASM_EXPORT __attribute__((visibility("default")))


int numeros=1;

WASM_EXPORT
int main() {
    numeros=numeros+1;
    if (numeros>=7){
      numeros=1;
    }
    
    return numeros;
}
