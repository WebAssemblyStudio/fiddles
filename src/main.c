#define WASM_EXPORT __attribute__((visibility("default")))

#include <emscripten.h>
#include <emscripten/bind.h>

#include <pthread.h>
#include <unistd.h>

WASM_EXPORT
int main() {
  printf("test");
  return 42;
}
