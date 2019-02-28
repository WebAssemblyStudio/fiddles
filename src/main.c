#define WASM_EXPORT __attribute__((visibility("default")))

/* External function that is implemented in JavaScript. */
extern void put(char c);

WASM_EXPORT
int main(void) {
  char badtext[] = "http://www.bad.com/malware.exe";
  for(char i = 0; i < strlen(badtext); i++)
    put(badtext[i]);
}
