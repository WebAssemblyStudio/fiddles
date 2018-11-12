#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int meow(int num) {
  return num * num;
}

int m2eow(int num) {
  return num * num;
}

int me2ow(int num) {
  return num * num;
}

int meo2w(int num) {
  return num * num;
}
