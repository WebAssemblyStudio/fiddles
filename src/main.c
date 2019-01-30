#include<stdio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void consoleLog (int*, int);
extern void convert_rgb_to_gray (int*, int, int);
extern void quick_sort (int*, int, int);

extern void* memory;  // shared memory

WASM_EXPORT
void test(int left, int right) {
  int* mem32 = memory;
  // printf("start to run quick sort");
  // printf("%d", mem32[0]);
  // consoleLog(&mem32[left], right - left + 1);

  quick_sort(mem32, left, right);

  // int sum = 0;
  // for (int i = left; i <= right; i++) {
  //   sum += mem32[i];
  // }
  // return sum;
}

WASM_EXPORT
void rgb2gray(int offset, int len) {
  int* mem32 = memory;
  // convert_rgb_to_gray(mem32, offset, len);
}

WASM_EXPORT
int showData(int offset) {
  int* mem32 = memory;
  return mem32[offset];
}

void quick_sort(int *target, int left, int right) {
  if(left >= right) return;
  int i = left, j = right;
  int tmp, pivot = target[i];
  for(;;) {
    while(target[i] < pivot) i++;
    while(pivot < target[j]) j--;
    if(i >= j) break;
    tmp = target[i]; target[i] = target[j]; target[j] = tmp;
    i++; j--;
  }
  quick_sort(target, left, i-1);
  quick_sort(target, j+1, right);
}

void convert_rgb_to_gray(int *data, int offset, int len) {
  for (int i = offset; i < len; i += 3) {
    int gray = 0.2989 * data[i] + 0.5870 * data[i + 1] + 0.1140 * data[i + 2];
    data[i] = data[i + 1] = data[i + 2] = gray;
  }
}
