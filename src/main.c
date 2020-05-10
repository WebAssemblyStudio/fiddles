#define WASM_EXPORT __attribute__((visibility("default")))

extern void consolelog(int c);
extern void consolelogstr(const char *c, int len);

WASM_EXPORT
int main(void) {
  consolelog(42);
  consolelogstr(&"Coucou", 6);
  // printf("toto");
  return 10;
}