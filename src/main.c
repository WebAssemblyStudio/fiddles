#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int test(int *p) {

  for(int i =0; i < 256 * 256; i++) {
    
    p[i]+=i;

  }

  return p[0];
}