#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 2021;
}

WASM_EXPORT
long count(int max) {
  int i;
  int j;
  int k;
  long result = 0;
  for (i = 1; i <= max; ++i)
  {
      for (j = 1; j <= max; ++j)
        {
          for (k = 1; k <= max/10; ++k)
          {
            result = result + 1;
          }
        }
    }
  return result;
}
