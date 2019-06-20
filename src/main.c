#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 66;
}

WASM_EXPORT
const char* getJson(){
  return "Türkçe fıstıkçı şahap";
}
