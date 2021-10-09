#include <stdio.h>
#include <sys/uio.h>
#include <stdlib.h>


#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  printf("Hello World\n");
}
typedef struct
{
  int x,y;
} Vector2;
WASM_EXPORT
Vector2* Vector2_new(int x,int y)
{
  Vector2 *c = malloc(sizeof(Vector2));
  c->x = x;
  c->y = y;
  return c;
}
WASM_EXPORT
int Vector2_get_x(Vector2* val)
{
  return val->x;
}
WASM_EXPORT
int Vector2_get_y(Vector2* val)
{
  return val->y;
}
WASM_EXPORT
void Vector2_delete(Vector2* val)
{
  free(val);
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
