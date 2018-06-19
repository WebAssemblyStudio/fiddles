#include <stdlib.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

export void *allocate(int size) {
    return malloc(size);
}

export void deallocate(void *ptr) {
    free(ptr);
}