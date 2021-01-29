#include <string.h>
#define WASM_EXPORT __attribute__((visibility("default")))

extern void alert(const char* str, int len);

WASM_EXPORT int main() {
  char str1[] = "hello";
  char str2[] = "bye";
  alert(str1, strlen(str1));
  alert(str2, strlen(str2));
}
