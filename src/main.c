#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
float power(float base, int pow) {

  float res = base;
  for (int i = 0; i < pow - 1; i++) {
    res = res * base;
  }

  return res;
}
