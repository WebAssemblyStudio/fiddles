#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/uio.h>
#include <stdint.h>

#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct _Vector {
  int length;
  uint8_t data[0];
} Vector;

WASM_EXPORT Vector* vec_create(int length) {
  Vector *vec = (Vector*) malloc(sizeof(Vector) + length);
  vec->length = length;
  return vec;
}

WASM_EXPORT void vec_destroy(Vector *vec) {
  free(vec);
}

WASM_EXPORT int vec_getLength(Vector* vec) { return vec->length; }
WASM_EXPORT uint8_t* vec_getData(Vector* vec) { return vec->data; }

typedef struct _Image {
  int width;
  int height;
  uint8_t data[0];
} Image;

WASM_EXPORT Image* img_create(int width, int height) {
  Image *img = (Image*) malloc(sizeof(Image) + width * height);
  img->width = width;
  img->height = height;
  return img;
}

WASM_EXPORT Image* img_createSimilar(Image *img) {
  return img_create(img->width, img->height);
}

WASM_EXPORT void img_destroy(Image *img) {
  free(img);
}

WASM_EXPORT int img_getWidth(Image* img) { return img->width; }
WASM_EXPORT int img_getHeight(Image* img) { return img->height; }
WASM_EXPORT uint8_t* img_getData(Image* img) { return img->data; }

WASM_EXPORT void convolve(Image *input, Image *output, Vector *impResp, int impRespOffset) {
  int w = output->width;
  int h = output->height;
  if (input->width != w || input->height != h) return;
  uint8_t *out = output->data;
  const uint8_t *inpStart = input->data;
  for (int y = 0; y < h; ++y) {
    int txStart = -impRespOffset;
    int irStart = 0;
    if (txStart < 0) {
      irStart = -txStart;
      txStart = 0;
    }
    const uint8_t *impRespStart = impResp->data + irStart;
    const uint8_t *impRespEnd = impResp->data + impResp->length;
    const uint8_t *inpEnd = inpStart + w;
    for (int x = 0; x < w; ++x) {
      const uint8_t *inp = inpStart + txStart;
      int msum = 0;
      for (const uint8_t *ir = impRespStart; ir < impRespEnd && inp < inpEnd; ++ir, ++inp) {
        msum += *ir * *inp;
      }

      *out = msum/255;
      
      if (irStart > 0) {
        --impRespStart;
        --irStart;
        ++txStart;
      }
      ++out;
    }
    inpStart += h;
  }
}

const uint8_t testImpResp[] = {0, 128, 0, 255, 128, 0, 0};
const uint8_t testImage1[] = {0, 0, 0, 32, 0, 0, 0};
const uint8_t testImage2[] = {32, 0, 0, 0, 0, 0, 0, 0, 0, 0};

WASM_EXPORT
int main(void) {
  Vector *impResp = vec_create(sizeof(testImpResp));
  memcpy(vec_getData(impResp), testImpResp, sizeof(testImpResp));
  Image *img1 = img_create(sizeof(testImage1), 1);
  memcpy(img_getData(img1), testImage1, sizeof(testImage1));
  Image *img2 = img_create(sizeof(testImage2), 1);
  memcpy(img_getData(img2), testImage2, sizeof(testImage2));
  
  Image *out1 = img_createSimilar(img1);
  convolve(img1, out1, impResp, -vec_getLength(impResp) >> 1);
  Image *out2 = img_createSimilar(img2);
  convolve(img2, out2, impResp, -vec_getLength(impResp) >> 1);

  img_destroy(img1);
  img_destroy(img2);
  vec_destroy(impResp);

  const uint8_t *buf;
  buf = img_getData(out1);
  for (int i = 0; i < img_getWidth(out1); ++i) {
    printf("%d ", buf[i]);
  }
  printf("\n");
  buf = img_getData(out2);
  for (int i = 0; i < img_getWidth(out2); ++i) {
    printf("%d ", buf[i]);
  }
  printf("\n");

  img_destroy(out1);
  img_destroy(out2);

  printf("Hello World\n");
  fprintf(stderr, "Error World\n");
}

/* External function that is implemented in JavaScript. */
extern void putcs_js(int fd, const void* c, int len);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    const struct iovec *v = iov + i;
    putcs_js(fd, v->iov_base, v->iov_len);
    cnt += v->iov_len;
  }
  return cnt;
}
