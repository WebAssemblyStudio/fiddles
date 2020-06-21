#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  float a = 3.14;
  double b = 6.28;
  double c = a * b;
  return (int)(c);
}
