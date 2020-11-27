#include <stdio.h>
#include <sys/uio.h>
#include <stdlib.h> 

#define WASM_EXPORT __attribute__((visibility("default")))



/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

struct socket
{
  int level;
  struct options
  {
    int optname;
    char* optval;
    int optlen;
  };
  struct options* options_arr[10];
};
struct socket* sockets[10];
WASM_EXPORT
int init_sockets_c()
{
  for(int i = 0; i <= 10; i++)
  {
    sockets[i] = malloc(sizeof(*sockets[1]));
    sockets[i]->level = i;
  }
  return 0;
}

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
WASM_EXPORT
int setsockopt_c(int level,int optname,char* optval, int optlen)
{
  if(sockets[level] != 0)
  {
    if(sockets[level]->level == level)
    {
      sockets[level]->options_arr[optname]->optval = optval;
      sockets[level]->options_arr[optname]->optlen = optlen;
      sockets[level]->options_arr[optname]->optname = optname;
      return (0);
    }
    return(118);
  }
}

WASM_EXPORT
int main(void) {
  init_sockets_c();
  printf("ciao");
  return setsockopt_c(1,112,"hello",312);
}