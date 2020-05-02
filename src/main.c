#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

int l3CacheBytesSize = 3145728;
int locations = 786432;
int evictionBuffer[786432];

void shuffle(int *evictionBuffer, int n) {
     int i, j, tmp;
     for (i = n - 1; i > 0; i--) {
         j = rand() % (i + 1);
         tmp = evictionBuffer[j];
         evictionBuffer[j] = evictionBuffer[i];
         evictionBuffer[i] = tmp;
     }
}

void prime() {
  srand(time(NULL));
  printf("Reported Cache Size: %li\n", l3CacheBytesSize);

  int start = clock();

  for (int i=0; i < 786432; i++) {
    evictionBuffer[i] = i;
  }

  shuffle(evictionBuffer, 786432);

  int end = clock();

  printf("%d\n", start);
  printf("%d\n", end);

  // Now Access the eviction buffer.
  int next = 0;
  for (int i = 0; i < 786432; i++) {
    next = evictionBuffer[next];
  }

  printf("%d\n", evictionBuffer[756431]);
}

void probe() {
  
}

WASM_EXPORT
int main(void) {

  prime();

  probe();
  
  return 0;
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
