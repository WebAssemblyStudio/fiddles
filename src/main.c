#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  char frase[]="questo è un test";
  printf("%s \n", frase);
  return 0;
}
