#define WASM_EXPORT __attribute__((visibility("default")))

/* External function that is implemented in Native Lauguage. */
extern void print(char *s);

char* itoa(int value, char* result, int base) {
  // check that the base if valid
  if (base < 2 || base > 36) { *result = '\0'; return result; }

  char* ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
  } while ( value );

  // Apply negative sign
  if (tmp_value < 0) *ptr++ = '-';
  *ptr-- = '\0';
  while(ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr--= *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

void printValue(char *title, int value) {
   char *p = title;
   int len = 0;
   while(*p ++) {
     len ++;
   }
   char buf[256];
   for(int i = 0; i < len; i ++) {
     buf[i] = title[i];
   }
   p = buf + i;
   itoa(value, p, 10);
   print(buf);
}

WASM_EXPORT
int main() {
  print("Hello World.");
  printValue("test", 100);
  return 42;
}
