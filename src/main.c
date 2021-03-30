#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}
WASM_EXPORT
char* demoPrinting(){
  return "Hello World\nThis Demo is for IT329 Report :)";
}