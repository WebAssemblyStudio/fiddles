#define WASM_EXPORT __attribute__((visibility("default")))

extern void wasm_log(char* start, int len);

WASM_EXPORT
int main() {
  wasm_log("Hello World!",12);
}