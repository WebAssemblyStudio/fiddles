#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
char *test()
{
  char *test = "<div>testing</div>";
  return test;
}
