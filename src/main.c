#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
long calculateFactorial(int number) {
  if (number > 1)
    return number * calculateFactorial(number - 1);
  else
    return number;
}
