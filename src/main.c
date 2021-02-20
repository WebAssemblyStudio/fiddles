#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
double* subtractArrays(double arr1[3], double const arr2[3]){
  arr1[0] -= arr2[0];
  arr1[1] -= arr2[1];
  arr1[2] -= arr2[2];
  return arr1;
}
