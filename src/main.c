#define WASM_EXPORT __attribute__((visibility("default")))

double leibnizPow(double i) {
  return pow(-1, i) / (2 * i + 1);
}

WASM_EXPORT
double leibniz(double n) {
  double r = .0;
  for (double i = 0; i < n; i++) {
    r += leibnizPow(i);
  }
  return 4 * r;
}
