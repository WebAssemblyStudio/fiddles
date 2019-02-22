#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 16;
float data[SIZE];

WASM_EXPORT
float* getData() {
  return &data[0];
}

WASM_EXPORT
void vec2add(float xa, float xb, float ya, float yb) {
  data[0] = xa + xb;
  data[1] = ya + yb;
}


WASM_EXPORT
float* mat4create() {
  float mat[16];
  return (float *) mat;
}

WASM_EXPORT
float* vec2create() {
  float mat[2] = {1., 2.};
  return (float *) mat;
}

WASM_EXPORT
void mat4multiply(float *a, float *b) {
  float a00 = a[0], a01 = a[1], a02 = a[2], a03 = a[3];
  float a10 = a[4], a11 = a[5], a12 = a[6], a13 = a[7];
  float a20 = a[8], a21 = a[9], a22 = a[10], a23 = a[11];
  float a30 = a[12], a31 = a[13], a32 = a[14], a33 = a[15];

  // Cache only the current line of the second matrix
  float b0  = b[0], b1 = b[1], b2 = b[2], b3 = b[3];
  data[0] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
  data[1] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
  data[2] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
  data[3] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

  b0 = b[4]; b1 = b[5]; b2 = b[6]; b3 = b[7];
  data[4] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
  data[5] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
  data[6] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
  data[7] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

  b0 = b[8]; b1 = b[9]; b2 = b[10]; b3 = b[11];
  data[8] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
  data[9] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
  data[10] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
  data[11] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

  b0 = b[12]; b1 = b[13]; b2 = b[14]; b3 = b[15];
  data[12] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
  data[13] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
  data[14] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
  data[15] = b0*a03 + b1*a13 + b2*a23 + b3*a33;
};