#define WASM_EXPORT __attribute__((visibility("default")))

extern void printchar(const char single);
void print(const char* pointer) {
  for (int i=0; i<13; i++) {
    printchar(pointer[i]);
  }
  return;
}

WASM_EXPORT
int main() {
  print("Hello, World!");
  return 42;
}
