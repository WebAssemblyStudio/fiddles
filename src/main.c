#define WASM_EXPORT __attribute__((visibility("default")))
#inclue "html.h"
WASM_EXPORT
int main() {
  return 42;
}
