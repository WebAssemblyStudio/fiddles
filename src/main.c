#define WASM_EXPORT __attribute__((visibility("default")))

extern void _putchar(char c);

void _printf(char* str) {
  int i=0;
  while(str[i]!='\0')
  {
    putc_js((int)str[i]);
    i++;
  }
  putc_js('\0');
}

WASM_EXPORT
int main() { 
  char* str="Hello World\n";
  _f(str);
  _printf("Hello Not World");
  return 0;
}
