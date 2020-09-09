#define WASM_EXPORT __attribute__((visibility("default")))

int func(int a, int b)
{
  return a * b;
}

WASM_EXPORT
int main() {
  return func(3,4);
}
