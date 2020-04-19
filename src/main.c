#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 6425;
}

WASM_EXPORT
char* hello() {
  return "hello there!";
}

WASM_EXPORT
double bignumber(double mynum)
{
  return mynum * 2;
}
