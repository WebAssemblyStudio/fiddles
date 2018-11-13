#define WASM_EXPORT __attribute__((visibility("default")))

void console_log(char c);

WASM_EXPORT
int test(char* str) {
  console_log(*str);
  return 42;
}
