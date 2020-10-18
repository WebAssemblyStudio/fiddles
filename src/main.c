#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int shift_left(int *p, int shift) {

  int shift_i = shift;

  for(int z = 0; z < 256; z++) {
  for(int y = 0; y < 256; y++) {
  for(int x = 0; x < 256; x++) {

    int i = x + y * 256  + z * 256 * 256;

    if(x < 256 - shift) {
p[i] = p[i + shift_i];
    } else {
      p[i] = 0;
    }

  }}}
      
  return 1;

}
