#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define WASM_EXPORT __attribute__((visibility("default")))

uint8_t sharedArray[10000];

WASM_EXPORT
uint8_t* getSharedArrayPtr() {
  return &sharedArray[0];
}

WASM_EXPORT
int bufferSum(uint8_t buffer_offset, int buffer_size)
{
  uint8_t* memory = sharedArray;
  uint8_t* buffer = (uint8_t*)(memory + buffer_offset);
  uint8_t res = 0;
  for (int i = 0; i < buffer_size; i++)
  {
      res += buffer[i];
  }
  return res;
}

WASM_EXPORT
void bufferOffset(uint8_t buffer_offset, int buffer_size)
{
    uint8_t* memory = sharedArray;
    uint8_t* buffer_res = (uint8_t*)(memory + buffer_offset + buffer_size);
    for (int i = 0; i < buffer_size; i++)
    {
        buffer_res[i] = i + 1;
    }
}
