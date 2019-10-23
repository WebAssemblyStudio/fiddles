#include <math.h>
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
float * ln(int n,int m){
float *tableau;
for(int i=1; n+i<m ;i++){
 tableau[i] = log(n+i) + n+i + sqrt(n+i);
}
return tableau;
}