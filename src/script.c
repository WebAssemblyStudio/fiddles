#define WASM_EXPORT __attribute__((visibility("default")))

extern int getCanvasWidth();
extern int getCanvasHeight();

int* heap;
int heap_start;

WASM_EXPORT
void init(int *arr, int offset) {
  heap = arr;
  heap_start = offset;
}

WASM_EXPORT
void channel() {
  int width = getCanvasWidth();
  int height = getCanvasHeight();
  int wh = width * height;
  int* image = &heap[heap_start];
  
  for(int i = 0; i < wh; i++) {
    image[i] = 255;
  }
}
