#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
void squareEach(int* p, int lim) {
      int r = 0;
    int g = 0;
    int b = 0;
  for (int i = 0; i < lim; i+=4) {

    //
      r = p[i];
      g = p[i + 1];
      b = p[i + 2];

      p[i] = 0.393 * r + 0.769 * g + 0.189 * b;
      p[i + 1] = 0.349 * r + 0.686 * g + 0.168 * b;
      p[i + 2] = 0.272 * r + 0.534 * g + 0.131 * b;
  }
}