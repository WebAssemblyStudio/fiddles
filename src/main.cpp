#define WASM_EXPORT __attribute__((visibility("default"))) extern "C"
#define WASM_IMPORT extern "C"


WASM_IMPORT void consoleLog (char* offset, int len);

char inStr[20];
char outStr[20];

WASM_EXPORT
char* getInStrOffset () {
  return &inStr[0];
}

WASM_EXPORT
void toLowerCase () {
  for (int i = 0; i < 20; i++) {
    char c = inStr[i];
    if (c > 64 && c < 91) {
      c = c + 32;
    }
    outStr[i] = c;
  }
  consoleLog(&outStr[0], 20);
}


/*

WASM_IMPORT void putc_js(char *);
WASM_IMPORT void consoleLog (char* offset, int len);

char str[] = "Hello World";

WASM_EXPORT
int main2(int x) {
  putc_js(&str[0]);
  return 42 + x;
}

char inStr[20];
char outStr[20];

WASM_EXPORT
char* getInStrOffset () {
  return &inStr[0];
}

WASM_EXPORT
void toLowerCase () {
  for (int i = 0; i < 20; i++) {
    char c = inStr[i];
    if (c > 64 && c < 91) {
      c = c + 32;
    }
    outStr[i] = c;
  }
  consoleLog(&outStr[0], 20);
}*/