#include <stdint.h>
#include <math.h>
#include <stdlib.h>

// 卷积操作，传入imageData像素数组的指针，imageData宽高，滤波器及滤波器宽高。
void conv(uint8_t *ptr, int width, int height, float* filter, int cw, int ch) {
  for (int i = ch / 2; i < height - ceil((float)ch / 2) + 1; i++) {
    for (int j = cw / 2; j < width - ceil((float)cw / 2) + 1; j++) {
      // rgba取前3个通道进行处理
      for (int k = 0; k < 3; k++) {
        float sum = 0;
        int count = 0;
        for (int x = -ch / 2; x < ceil((float)ch / 2); x++) {
          for (int y = -cw / 2; y < ceil((float)cw / 2); y++) {
            sum += filter[count] * (float)ptr[((i+x)*width+(y+j))*4+k];
            count++;
          }
        }
        ptr[(i*width+j)*4+k] = (uint8_t)sum;
      }
    }
  }
}

#ifdef __cplusplus
extern "C"
{
#endif

  // 供js调用的函数，传入像素数组的指针，宽高，以及滤波器的宽高
  // 这里为了简单，默认滤波器矩阵每一项的值相同，即1/(cw*ch)。
  void easyBlur(uint8_t *ptr, int width, int height, int cw, int ch) {
    float* filter = malloc(cw * ch*sizeof(int));
    float value = 1 / (float)(cw * ch);
    for (int i = 0; i < cw * ch; i++) {
      filter[i] = value;
    }
    conv(ptr, width, height, filter, cw, ch);
    free(filter);
  }

#ifdef __cplusplus
}
#endif