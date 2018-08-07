#define WASM_EXPORT __attribute__((visibility("default")))

#define min(X, Y) ((X) < (Y) ? (X) : (Y))

WASM_EXPORT
void matmul(float* aValues, float* bValues, 
            unsigned int leftDim, unsigned int rightDim, 
           unsigned int sharedDim, unsigned int aOuterStep, unsigned int aInnerStep, 
           unsigned int bOuterStep,unsigned int bInnerStep,
           unsigned int blockSize,
           float* result) {

    for (unsigned i0 = 0; i0 < leftDim; i0 += blockSize) {
      for (unsigned j0 = 0; j0 < rightDim; j0 += blockSize) {
        for (unsigned k0 = 0; k0 < sharedDim; k0 += blockSize) {
          // for when blockSize doesn't evenly divide the input
          unsigned iBlock = min(i0 + blockSize, leftDim);
          unsigned jBlock = min(j0 + blockSize, rightDim);
          unsigned kBlock = min(k0 + blockSize, sharedDim);

          for (unsigned i = i0; i < iBlock; i++) {
            for (unsigned j = j0; j < jBlock; j++) {
              float sum = 0.0;

              for (unsigned k = k0; k < kBlock; k++) {
                sum += aValues[i * aOuterStep + k * aInnerStep] *
                    bValues[k * bInnerStep + j * bOuterStep];
              }
              result[i * rightDim + j] += sum;
            }
          }
        }
      }
    }
}
