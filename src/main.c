#define WASM_EXPORT __attribute__((visibility("default")))

/* External function which is implemented in JavaScript. */
extern void putstr_js(char* str,char count);

WASM_EXPORT int main(void) {
  putstr_js("hello world",11);
}

