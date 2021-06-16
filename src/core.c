#define WASM_EXPORT __attribute__((visibility("default")))

unsigned int val = 0;

WASM_EXPORT
void store(int v) {
  val = v;
}

WASM_EXPORT
int get() {
  return val;
}

WASM_EXPORT
void inc() {
  val = val+1;
}
