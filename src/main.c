#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/uio.h>
#include <sys/time.h>

#define WASM_EXPORT __attribute__((visibility("default")))

//定义数组长度
#define LENGTH 10000000
//定义斐波那契数列
long* fibonaccis(long n) {
    long *fib = malloc(sizeof(long) * n);
    fib[0] = 1;
    fib[1] = 1;
    if(n <= 2){
        return fib;
    }
    for(int i = 2;i < n;i++){
        fib[i] =fib[i-2] + fib[i-1];
    }

    return fib;
}


int cmp ( const void *a , const void *b ) { 
    return *(int *)a - *(int *)b; 
}

/* 测试排序方法 */
WASM_EXPORT
int test_sort() {
  int *arr = malloc(sizeof(int) * LENGTH);
    
  srand(time(0));
  for(int i = 0; i < LENGTH;i++){
      arr[i] = rand() % 1000;
  }
  qsort(arr,LENGTH,sizeof(int),cmp);
  free(arr);
}

/* 测试计算斐波那契方法 */
WASM_EXPORT
int test_fibonacci() {
  long *fib = fibonaccis(LENGTH);
  free(fib);
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