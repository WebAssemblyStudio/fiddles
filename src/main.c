#define WASM_EXPORT __attribute__((visibility("default")))

#define u8  unsigned char
#define u32 unsigned int
#define i32 signed   int

WASM_EXPORT
void _update(u32 *buf, u32 width, u32 height, u32 deltatime) {
  for (u32 y = 0; y < height; y++)
    for (u32 x = 0; x < width; x++)
      *buf++ = 0xff0102ff;
}