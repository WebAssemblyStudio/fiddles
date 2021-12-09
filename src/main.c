#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(int a, int b, int c) {
  if (a == b) {
    return a;
  } else {
    if (b == c) {
      return b;
    } else {
      return c;
    }
  }
}