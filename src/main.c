#define WASM_EXPORT __attribute__((visibility("default")))

void getv(int idx, int* ptr);

WASM_EXPORT
int sum(int idx) {
  int v;
  getv(idx, &v);
  if (idx > 0) {
    v += sum(idx - 1);
  }
  return v;
}
