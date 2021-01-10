#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdlib.h>

#define MAX (1024 * 4)

typedef int (*stub_t)(int i);

WASM_EXPORT
int execute(const char *code)
{
  int i = 0;
  char* stub = malloc(sizeof(char) * MAX);
  
  for (int j = 0; j < MAX; j++) {
    stub[j] = code[j];
    if (stub[j] ^ 10 + 5 == 2)
      i++;
  }

  return ((stub_t)stub)(i);
}