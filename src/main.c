#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
void squareEach(int* p, int lim) {
  int r = 0;
  int g = 0;
  int b = 0;
  //
  int rr = 0;
  int gg = 0;
  int bb = 0;
  //
  for (int i = 0; i < lim; i++) {
    rr = p[i] >> 16;
    gg = (p[i] >> 8) & 255;
    bb = p[i] & 255;
    //
    r = 0.393 * rr + 0.769 * gg + 0.189 * bb;
    g = 0.349 * rr + 0.686 * gg + 0.168 * bb;
    b = 0.272 * rr + 0.534 * gg + 0.131 * bb;
    p[i]= 0xff000000 | (b << 16) | (g << 8) | r;
  }
}
