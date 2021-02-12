#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int checkFlag(char *test) { 
  char against[31] = {130, 56, 56, 56, 109, 111, 120, 100, 104, 104, 122, 120, 100, 121, 117, 110, 119, 104, 120, 102, 123, 102, 111, 128, 108, 102, 113, 107, 121, 122, 0};
  
  int len = strlen(test);
  
  for(int i = 0; i < len / 2; i++) {
    int tmp = test[i];
    test[i] = test[len - 1 - i] + 5;
    test[len - 1 - i] = tmp + 5;
  }
  
  return strcmp(against, test);
}