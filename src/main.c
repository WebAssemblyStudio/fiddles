#define WASM_EXPORT __attribute__((visibility("default")))

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

WASM_EXPORT
int main(void) {
  char badtext[] = "text from webasembly";
  for(char i = 0; i < strlen(badtext); i++)
    putc_js(badtext[i]);
}
