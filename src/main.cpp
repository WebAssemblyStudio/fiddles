
#include <algorithm>
using namespace std;
#define WASM_EXPORT __attribute__((visibility("default")))

int arr[10];
extern "C" {
int getSize();
int  WASM_EXPORT *getArrayOffset() { return arr; }
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
  quickSort(arr, 0, size);
}
}