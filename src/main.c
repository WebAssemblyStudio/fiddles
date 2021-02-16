#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int bufferSum(uint8_t buffer_offset, int buffer_size)
{
  uint8_t* memory = 0;
  uint8_t* buffer = (uint8_t*)(memory + buffer_offset);
  uint8_t res = 0;
  for (int i = 0; i < buffer_size; i++)
  {
      res += buffer[i];
  }
  return res;
}

