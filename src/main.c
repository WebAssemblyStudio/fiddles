#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(int x, int y, char **) {
  x=5;
  y=6;
  return x+y;
}

