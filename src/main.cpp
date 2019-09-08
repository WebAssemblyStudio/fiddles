
#include <algorithm>
#include <sys/uio.h>
using namespace std;
#define WASM_EXPORT __attribute__((visibility("default")))

int *arr;
extern "C" {
int getSize();
void putc_js(char c);
/* Basic implementation of the writev sys call. */
size_t WASM_EXPORT writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      putc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  return cnt;
}

int WASM_EXPORT *getArrayOffset() { return arr; }
void quickSort(const int *array, int start, int end) {
  if (end - start <= 0)
    return;
  int left = start;
  int right = end - 1;
  while (left < right) {
    if (arr[left] > arr[left + 1]) {
      swap(arr[left], arr[left + 1]);
      left++;
    } else {
      swap(arr[right], arr[left + 1]);
      right--;
    }
  }
  quickSort(arr, start, left);
  quickSort(arr, left + 1, end);
}

void WASM_EXPORT sort() {
  int size = getSize();
  arr = new int[size];
  quickSort(arr, 0, size);
}
}