#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  __asm (
    "i32.const 12\n"
    "i32.const 34\n"
    "i32.add     \n"
    "br 0"
  );
}
