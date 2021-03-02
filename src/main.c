#include <stdlib.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
long encode(long l1, long s2, long s3)
{
  return ((0x01L << 32) << l1) + ((0x01L << 16) << s2) + (0x01 << s3);
}
WASM_EXPORT
long checkMain(long id, long mask)
{
  return ((id >> 32) & 0xFFFFL) & (0x01 << mask);
}
WASM_EXPORT
long checkSub(long id, long mask)
{
  return ((id >> 16) & 0xFFFFL) & (0x01 << mask);
}
WASM_EXPORT
long checkSubSon(long id, long mask)
{
  return (id & 0xFFFFL) & (0x01 << mask);
}