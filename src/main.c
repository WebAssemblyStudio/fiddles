#define WASM_EXPORT __attribute__((visibility("default")))

extern int get_magic_number();

WASM_EXPORT
int main() {
  return get_magic_number();
}