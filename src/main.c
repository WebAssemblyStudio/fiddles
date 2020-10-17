#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int test(int *p, int shiftX, int shiftY, int shiftZ) {
  
  for(int i = 0; i < 256 * 256 * 256 - 1; i++) {

    int shift = (x + shiftX) + (y + shiftY) * 256 + (z + shiftZ) * 256 * 256;
    
    p[i] = p[i + 1] + 1;

  }

  return 0;
}