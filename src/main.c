#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

// WASM_EXPORT
// int main(void) {
//   printf("Hello World\n");
// }

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


#include <pthread.h>
#include <stdio.h>

// Calculate Fibonacci numbers shared function
int fibonacci(int iterations) {
    int     val = 1;
    int     last = 0;

    if (iterations == 0) {
        return 0;
    }
    for (int i = 1; i < iterations; i++) {
        int     seq;

        seq = val + last;
        last = val;
        val = seq;
    }
    return val;
}
// Start function for the background thread
void *bg_func(void *arg) {
    int     *iter = (void *)arg;

    *iter = fibonacci(*iter);
    return arg;
}
// Foreground thread and main entry point
WASM_EXPORT
int main(int argc, char *argv[]) {
    int         fg_val = 540;
    int         bg_val = 420;
    pthread_t   bg_thread;

    // Create the background thread
    // if (pthread_create(&bg_thread, NULL, bg_func, &bg_val)) {
    //     perror("Thread create failed");
    //     return 1;
    // }
    // Calculate on the foreground thread
    fg_val = fibonacci(fg_val);
    // Wait for background thread to finish
    // if (pthread_join(bg_thread, NULL)) {
    //     perror("Thread join failed");
    //     return 2;
    // }
    // Show the result from background and foreground threads
    printf("Fib(42) is %d, Fib(6 * 9) is %d\n", bg_val, fg_val);

    return 0;
}