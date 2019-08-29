
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
#include <iostream.h>
#include <cstdlib.h>
#include <ctime.h>
int main()
{
  return 32;
}
