#define WASM_EXPORT __attribute__((visibility("default")))

/* External function */
extern void v1x1_write(char *p, int len);

WASM_EXPORT
void main(void) {
  v1x1_write("Hello World\n", 12);
}