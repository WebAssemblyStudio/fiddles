#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>

WASM_EXPORT
double logx(double x) {
  return log(x);
}
