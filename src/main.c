#define WASM_EXPORT __attribute__((visibility("default")))

extern void console_log(char* string);

WASM_EXPORT
int main() {
  console_log("Test");

  return 42;
}
