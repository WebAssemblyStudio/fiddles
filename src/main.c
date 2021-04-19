#define WASM_EXPORT __attribute__((visibility("default")))

#include <sys/time.h>
#include <stdio.h>

WASM_EXPORT
int main() {
  struct timeval current_time;
  gettimeofday(&current_time, NULL);
  printf("seconds : %ld\nmicro seconds : %ld",
    current_time.tv_sec, current_time.tv_usec);

  return 0;
}
