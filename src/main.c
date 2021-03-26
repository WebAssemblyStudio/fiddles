#include <stdio.h>
#include <sys/uio.h>
#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

#define SWAP_SPEED 800.0f;

WASM_EXPORT float move_swap(float cur, float next, float ddd) 
{
  float v = cur - SWAP_SPEED * ddd;

  if (cur > next)
  {
    if(v > next) return next;

    return v;
  }

  if(v < next) return v;

  return next;
}

