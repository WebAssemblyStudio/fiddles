#define WASM_EXPORT __attribute__((visibility("default")))

extern "C" {

  WASM_EXPORT
  int main()
  {
    return 0;
  }

  WASM_EXPORT
  double add(double x, double y)
  {
    return x + y;
  }
}