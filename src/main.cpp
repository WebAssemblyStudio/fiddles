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

  WASM_EXPORT
  double getNumber()
  {
    int x = 0;
    for (int i = 0; i < 999999999; i++){
      x = i;
    }
    return x;
  }
}