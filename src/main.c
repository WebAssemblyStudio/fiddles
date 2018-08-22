#define WASM_EXPORT __attribute__((visibility("default")))

long long g = 999999999999999999ll;
long long g2 = 1;

WASM_EXPORT
int main() {
  return 42;
}

extern long long fn(long long);

WASM_EXPORT
long long test() {
  g2++;
  return fn(g);
}
