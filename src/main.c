#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  printf("Hello World\n");
  return -1;
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      putc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  putc_js((char)fd);
  return cnt;
}

/*Web Assembly Memory test*/
WASM_EXPORT 
const char* imageBinary(const char* pBuf, size_t w, size_t h,size_t channel, int threshold)
{
   char* pRet = malloc(w*h*channel);
   for(size_t i = 0; i < h; i++)
   {
     for(size_t j = 0; j < w; j++)
     {
       for(size_t k = 0; k < channel; k++)
       {
         pRet[(i*w+j)*channel + k] = pBuf[(i*w+j)*channel + k] < threshold ?0:255;
       }
     }
   }
   return pRet;
}

WASM_EXPORT 
void releaseInternalMemory(const char* p)
{
  if(0 != p)
  {
    free(p);
    p = 0;
  }
}
