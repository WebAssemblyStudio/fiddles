#define WASM_EXPORT __attribute__((visibility("default")))

/* External function that is implemented in Native Lauguage. */
extern void print(char *s);

WASM_EXPORT
int main() {
  print("Hello World.\n");
  return 43;
}
