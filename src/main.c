#define WASM_EXPORT __attribute__((visibility("default")))

int data[256 * 256 * 256];

int* getDataPointer() {

  return &data[0];

}

WASM_EXPORT
int test(int *p, int shiftX, int shiftY, int shiftZ) {

  int temp[256 * 256 * 256];
  int shift = shiftX + shiftY * 256 + shiftZ * 256 * 256;

  for(int i = 0; i < 256 * 256 * 256 - 1; i++) {
      
    int src_i = i;
		int dst_i = i + shift;

    p[src_i]++;

    temp[dst_i] = p[src_i];

  }

  // memcpy(p, &temp, 256 * 256 * 256 * 4);

  return 0;
}