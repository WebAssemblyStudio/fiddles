#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
char * test() {
  return "Türkçe Fıstıkçı Şahap";
}

WASM_EXPORT
int fileLoad(int *buffer, int size) {
  return size;
}
