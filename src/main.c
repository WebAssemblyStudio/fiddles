#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 100;
}

WASM_EXPORT 
int Add(int a,int b){
  return a+b;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define MAXLINE 4096

WASM_EXPORT
int BeginConnect(){
    int    sockfd, n;
    char    recvline[4096], sendline[4096];
    struct sockaddr_in    servaddr;

    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
    printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);

    if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
    printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
    exit(0);
    }

    printf("send msg to server: \n");
    fgets(sendline, 4096, stdin);
    if( send(sockfd, sendline, strlen(sendline), 0) < 0)
    {
    printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
    }

    close(sockfd);
    exit(0);
}