#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int shift(int *p, int *t, int shiftX, int shiftY, int shiftZ) {

  int shift_i = shiftX + shiftY * 256 + shiftZ * 256 * 256;

  for(int z = 0; z < 256; z++) {
  for(int y = 0; y < 256; y++) {
  for(int x = 0; x < 256; x++) {

    int i = x + y * 256  + z * 256 * 256;

    p[i + shift_i] = x + shiftX < 0 ? 0 : p[i];


  }}}
      
  return 1;

}
