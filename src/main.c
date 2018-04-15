#define WASM_EXPORT __attribute__((visibility("default")))

#include <malloc.h>

unsigned int double_numbers[10];

WASM_EXPORT
unsigned int compute(unsigned int *numbers, int size) {
  //unsigned int *double_numbers = malloc(sizeof(unsigned int)*size);
  for (int i = 0; i < size; i++) {
    double_numbers[i] = numbers[i] * 2;
  }
  return (unsigned int)double_numbers;
}
