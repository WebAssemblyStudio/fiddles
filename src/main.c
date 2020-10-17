#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int test(int *p) {
  
  for(int i = 0; i < 256 * 256 * 256 - 1; i++) {
    
    p[i] = p[i + 1] + 1;

  }

  return 0;
}