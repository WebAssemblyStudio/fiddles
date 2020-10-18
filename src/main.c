#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int shift_left(int *p, int shift) {

  int shift_i = shift;

  for(int z = 0; z < 256; z++) {
  for(int y = 0; y < 256; y++) {
  for(int x = 0; x < 256; x++) {

    int i = x + y * 256  + z * 256 * 256;

    p[i + shift_i] = x + shift < 0 ? 0 : p[i];


  }}}
      
  return 1;

}
