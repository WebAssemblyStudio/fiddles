#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int sum(char *ptr, int len) {
  int result = 0;
  for(int i=0; i<len; ++i) result += ptr[i];
  return result;
}
