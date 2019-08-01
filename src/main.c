#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int fahrToCels(int fahr)
{
  return 5 * (fahr - 32) / 9;
}

WASM_EXPORT
int celsToFahr(int cels)
{
  return ((cels * 9) / 5) + 32;
}
