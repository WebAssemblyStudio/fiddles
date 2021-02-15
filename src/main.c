#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

extern unsigned char __heap_base;

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
void * get_heap_base() {
  return &__heap_base;
}

WASM_EXPORT
int bufferSum(uint8_t buffer_offset, int buffer_size)
{
  uint8_t* memory = 0;
  uint8_t* buffer = (uint8_t*)(memory + buffer_offset);
  uint8_t res = 0;
  for (int i = 0; i < buffer_size; i++)
  {
      res = res + buffer[i];
  }
  return res;
}

WASM_EXPORT
void bufferOffset(uint8_t buffer_offset, int buffer_size)
{
    uint8_t* memory = 0;
    uint8_t* buffer_res = (uint8_t*)(memory + buffer_offset + buffer_size);
    for (int i = 0; i < buffer_size; i++)
    {
        buffer_res[i] = i + 1;
    }
}
