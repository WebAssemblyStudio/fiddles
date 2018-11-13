#define WASM_EXPORT __attribute__((visibility("default")))

extern int getCanvasWidth();
extern int getCanvasHeight();

int* heap;
int heapStart;

WASM_EXPORT
void init(int *arr, int offset) {
  heap = arr;
  heapStart = offset;
}

// Full int32 range is -0x80000000 to 0x7FFFFFFF. Use half.
int applyCap(x) {
  return x < -0x40000000 ? -0x40000000 : (x > 0x3FFFFFFF ? 0x3FFFFFFF : x);
}

unsigned int toRGB(x) {
  // Map negative values to red, positive to blue-green, zero to black
  int val = x >> 22;
  if (val < 0) {
    return ((-(val + 1)) | 0xFF000000); // red
  }
  return (((val << 8) | (val << 16)) | 0xFF000000); // cyan
}

WASM_EXPORT
void step() {
  int width = getCanvasWidth();
  int height = getCanvasHeight();
  int wh = width * height;
  int intOffset = heapStart >> 2;
  int* image = &heap[intOffset];
  int* force = &heap[intOffset + wh];
  int* status = &heap[intOffset + wh + wh];
  int* u = &heap[intOffset + wh + wh + wh];
  int* vel = &heap[intOffset + wh + wh + wh + wh];

  for (int i=0; i < height; i++) {
    status[i * width] = 1;
    status[i * width + width - 1] = 1;
  }

  for (int i=0; i < width; i++) {
    status[i] = 1;
    status[width * height - width + i] = 1;
  }

  for (int i=0; i < wh; i++) {
    if (status[i] == 0) {
      int uCen = u[i];
      int uNorth = u[i - width];
      int uSouth = u[i + width];
      int uEast = u[i + 1];
      int uWest = u[i - 1];
      int uxx = (((uWest + uEast) >> 1) - uCen);
      int uyy = (((uNorth + uSouth) >> 1) - uCen);
      vel[i] = applyCap(vel[i] + (uxx >> 1) + (uyy >> 1));
    }
  }

  for (int i = 0; i < wh; i++) {
    if (status[i] == 0) {
      int f = force[i];
      u[i] = applyCap(f + applyCap(u[i] + vel[i]));
      force[i] = f >> 1;
    }
  }

  for (int i = 0; i < wh; i++) {
    if (status[i] == 1) {
      image[i] = 0xFFFF0000;
    } else {
      image[i] = toRGB(u[i]);
    }
  }
}
