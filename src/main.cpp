#include <stdint.h>
#include <cmath>
#include <cfenv>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}


template <typename T>
static bool plus_checked(T a, T b, T *c);

template <>
bool plus_checked<int8_t>(int8_t a, int8_t b, int8_t *c) {
  int16_t ia = a, ib = b;
  int16_t ic = ia + ib;
  if (ic >> 8) {
    return true;
  }
  *c = ic & 0xFF;
  return false;
}
  
template <>
bool plus_checked<int32_t>(int32_t a, int32_t b, int32_t *c) {
  return __builtin_sadd_overflow(a, b, c);
}
template <>
bool plus_checked<int64_t>(int64_t a, int64_t b, int64_t *c) {
  return __builtin_saddll_overflow(a, b, c);
}

WASM_EXPORT bool plus(int8_t *c, int8_t a,  int8_t b) {
  return plus_checked(a, b, c);
}
WASM_EXPORT bool plus(int32_t *c, int32_t a,  int32_t b) {
  return plus_checked(a, b, c);
}
WASM_EXPORT bool plus(int64_t *c, int64_t a,  int64_t b) {
  return plus_checked(a, b, c);
}


static bool check_overflow() noexcept {
  const auto fptest = FE_INEXACT | FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW;
  const auto &except = std::fetestexcept(fptest);
  if (except) {
    return true;
  }
  return false;
}

WASM_EXPORT bool cos(float *res, float a) {
  *res = std::cos(a);
  return check_overflow();
}
WASM_EXPORT bool cos(double *res, double a) {
  *res = std::cos(a);
  return check_overflow();
}
WASM_EXPORT bool acos(float *res, float a) {
  *res = std::acos(a);
  return check_overflow();
}
WASM_EXPORT bool acos(double *res, double a) {
  *res = std::acos(a);
  return check_overflow();
}