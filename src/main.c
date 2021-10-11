#include <stdio.h>
#include <sys/uio.h>
#include <string.h>
#include <stdlib.h>

#define WASM_EXPORT __attribute__((visibility("default")))
typedef int (*fptr_type)(void);

typedef struct
{
  float x,y;
} Vector2;
WASM_EXPORT
Vector2* Vector2_new(int x,int y)
{
  Vector2* v2 = malloc(sizeof(Vector2));
  v2->x = x;
  v2->y = y;
  return v2;
}
WASM_EXPORT
int main(void) {
  printf("Hello World\n");
  return 2;
}

WASM_EXPORT
float GetArea(Vector2* e)
{
  return e->x * e->y;
}
WASM_EXPORT
float Vector2_get_magnitude(Vector2* e)
{
  return e->x * e->x + e->y * e->y;
}
WASM_EXPORT
Vector2* Vector2_Sub(Vector2* a,Vector2* b)
{
  Vector2* val = malloc(sizeof(Vector2));
  val->x = a->x-b->x;
  val->y = b->y-b->y;
  return val;
}
WASM_EXPORT
float Vector2_Distance(Vector2* a,Vector2* b)
{
  Vector2* val = Vector2_Sub(a,b);
  float ret = Vector2_get_magnitude(val);
  free(val);
  return ret;
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
  return cnt;
}
