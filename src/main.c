#define WASM_EXPORT __attribute__((visibility("default")))

void somefunc(char* t);

WASM_EXPORT
int main() {
  char* p = "messaged";
  somefunc(p);
  return 42;
}
