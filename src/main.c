#include <inttypes.h>
#include <stdio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
void show(uint8_t arr[]) {
    size_t size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        printf("%02x", arr[i]);
    }
    printf("\n");
}

WASM_EXPORT
void copy(uint8_t src[], uint8_t dest[]) {
    size_t size = sizeof(src) / sizeof(src[0]);
    for (int i = 0; i < size; i++) {
        dest[i] = 32 + i;
    }
}