#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main()
{
}
static float som;
WASM_EXPORT
int sommeer(float *b, int length)
{
  // float som = 0;
  int a[] = {1, 2, 3, 4, 5};

  for (int i = 0; i < length; i++)
  {
    // a[i] = b[i];
    som = som + a[i];
  }
  return som;
}
