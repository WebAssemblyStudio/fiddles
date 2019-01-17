// #include<stdio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

extern void quick_sort(int*, int, int);

WASM_EXPORT
int* test(int* arr, int left, int right) {
  // printf("start to run quick sort");
  quick_sort(arr, left, right);
  return arr;
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
