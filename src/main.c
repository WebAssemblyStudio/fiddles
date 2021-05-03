#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
#include <stdbool.h>
bool es_natural(int numero)
{
   return numero > 0;
}

