#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  long ebayteppich = 92387283923.1239813;
  printf("Teppich: %d \n", sizeof(ebayteppich));
  return 42;
}
