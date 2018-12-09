#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <assert.h>
//#include <emscripten.h>
#define HOST_ADDR "192.168.18.61"

int result = 0;
int sock;
char buf[16] = "emscripten";
struct sockaddr_in si_host;
struct iovec iov[1];
struct msghdr hdr;
#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void)
{
  memset(&si_host, 0, sizeof(struct sockaddr_in));

  si_host.sin_family = AF_INET;
  si_host.sin_port = htons(13337);
  if(0 == inet_pton(AF_INET, HOST_ADDR, &si_host.sin_addr)) {
    perror("inet_aton failed");
    exit(EXIT_FAILURE);
  }

  if(-1 == (sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP))) {
    perror("cannot create socket");
    exit(EXIT_FAILURE);
  }

  iov[0].iov_base = buf;
  iov[0].iov_len = sizeof(buf);

  memset (&hdr, 0, sizeof (struct msghdr));

  hdr.msg_name = &si_host;
  hdr.msg_namelen = sizeof(struct sockaddr_in);
  hdr.msg_iov = iov;
  hdr.msg_iovlen = 1;

  int n = sendmsg(sock, &hdr, 0);
  
  sprintf( "send %d", n);

  return EXIT_SUCCESS;
}