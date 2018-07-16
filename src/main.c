#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

struct Vector {
  int length;
  char data[0];
}

WASM_EXPORT Vector* vec_create(int length) {
  return (Vector*) malloc(sizeof(Vector) + length);
}

WASM_EXPORT void vec_destroy(Vector *vec) {
  free(vec);
}

WASM_EXPORT int vec_getLength(Vector* vec) { return vec->length; }
WASM_EXPORT char* vec_getData(Vector* vec) { return vec->data; }

struct Image {
  int width;
  int height;
  char data[0];
}

WASM_EXPORT Image* img_create(int width, int height) {
  return (Image*) malloc(sizeof(Image) + width * height);
}

WASM_EXPORT void img_destroy(Image *img) {
  free(img);
}

WASM_EXPORT int img_getWidth(Image* img) { return img->width; }
WASM_EXPORT int img_getHeight(Image* img) { return img->height; }
WASM_EXPORT char* img_getData(Image* img) { return img->data; }

WASM_EXPORT void convolve(Image *input, Image *output, Vector *impResp, int impRespOffset) {
  int w = output->width;
  int h = output->height;
  if (input->width != w || input->height != h) return;
  char *out = output->data;
  const char *inpStart = input->data;
  for (int y = 0; y < h; ++y) {
    int txStart = -impRespOffset;
    int irStart = 0;
    if (txStart < 0) {
      irStart = -txStart;
      txStart = 0;
    }
    const char *impRespStart = impResp->data + irStart;
    const char *impRespEnd = impResp->data + impResp->length;
    const char *inp = inpStart;
    for (int x = 0; x < w; ++x) {
      int tx = txStart;
      int sum = 0;
      for (const char *ir = impRespStart; ir < impRespEnd; ++ir) {
        sum += *ir * *inp;
      }
      
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

WASM_EXPORT
int main(void) {
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
