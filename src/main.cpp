#define WASM_EXPORT __attribute__((visibility("default")))

#include <inttypes.h>

void rotate(int inputWidth,
            int inputHeight,
            int d1Start,
            int d1Limit,
            int d1Advance,
            int d1Multiplier,
            int d2Start,
            int d2Limit,
            int d2Advance,
            int d2Multiplier) {
  int bpp = 4;
  int imageSize = inputWidth * inputHeight * bpp;
  uint32_t* inBuffer = (uint32_t*) 4;
  uint32_t* outBuffer = (uint32_t*) (imageSize + 4);

  int i = 0;
  for (int d2 = d2Start; d2 >= 0 && d2 < d2Limit; d2 += d2Advance) {
    for (int d1 = d1Start; d1 >= 0 && d1 < d1Limit; d1 += d1Advance) {
      int in_idx = ((d1 * d1Multiplier) + (d2 * d2Multiplier));
      outBuffer[i] = inBuffer[in_idx];
      i += 1;
    }
  }
}

WASM_EXPORT
void rotate(int inputWidth, int inputHeight, int angle) {
  switch (angle) {
    default:
      rotate(inputWidth, inputHeight, 0, inputWidth, 1, 1, 0, inputHeight, 1,
             inputWidth);
      break;
    case 90:
      rotate(inputWidth, inputHeight, inputHeight - 1, inputHeight, -1,
             inputWidth, 0, inputWidth, 1, 1);
      break;
    case 180:
      rotate(inputWidth, inputHeight, inputWidth - 1, inputWidth, -1, 1,
             inputHeight - 1, inputHeight, -1, inputWidth);
      break;
    case 270:
      rotate(inputWidth, inputHeight, 0, inputHeight, 1, inputWidth,
             inputWidth - 1, inputWidth, -1, 1);
      break;
  }
}
