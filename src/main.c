#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT int wasm___fpclassify(double a) {
  return __fpclassify(a);
}
WASM_EXPORT int wasm___fpclassifyf(float a) {
  return __fpclassifyf(a);
}
WASM_EXPORT int wasm___fpclassifyl(long double a) {
  return __fpclassifyl(a);
}

WASM_EXPORT int wasm___signbit(double a) {
  return __signbit(a);
}
WASM_EXPORT int wasm___signbitf(float a) {
  return __signbitf(a);
}
WASM_EXPORT int wasm___signbitl(long double a) {
  return __signbitl(a);
}

WASM_EXPORT double      wasm_acos(double a) {
  return acos(a);
}
WASM_EXPORT float       wasm_acosf(float a) {
  return acosf(a);
}
WASM_EXPORT long double wasm_acosl(long double a) {
  return acosl(a);
}

WASM_EXPORT double      wasm_acosh(double a) {
  return acosh(a);
}
WASM_EXPORT float       wasm_acoshf(float a) {
  return acoshf(a);
}
WASM_EXPORT long double wasm_acoshl(long double a) {
  return acoshl(a);
}

WASM_EXPORT double      wasm_asin(double a) {
  return asin(a);
}
WASM_EXPORT float       wasm_asinf(float a) {
  return asinf(a);
}
WASM_EXPORT long double wasm_asinl(long double a) {
  return asinl(a);
}

WASM_EXPORT double      wasm_asinh(double a) {
  return asinh(a);
}
WASM_EXPORT float       wasm_asinhf(float a) {
  return asinhf(a);
}
WASM_EXPORT long double wasm_asinhl(long double a) {
  return asinhl(a);
}

WASM_EXPORT double      wasm_atan(double a) {
  return atan(a);
}
WASM_EXPORT float       wasm_atanf(float a) {
  return atanf(a);
}
WASM_EXPORT long double wasm_atanl(long double a) {
  return atanl(a);
}

WASM_EXPORT double      wasm_atan2(double a, double b) {
  return atan2(a, b);
}
WASM_EXPORT float       wasm_atan2f(float a, float b) {
  return atan2f(a, b);
}
WASM_EXPORT long double wasm_atan2l(long double a, long double b) {
  return atan2l(a, b);
}

WASM_EXPORT double      wasm_atanh(double a) {
  return atanh(a);
}
WASM_EXPORT float       wasm_atanhf(float a) {
  return atanhf(a);
}
WASM_EXPORT long double wasm_atanhl(long double a) {
  return atanhl(a);
}

WASM_EXPORT double      wasm_cbrt(double a) {
  return cbrt(a);
}
WASM_EXPORT float       wasm_cbrtf(float a) {
  return cbrtf(a);
}
WASM_EXPORT long double wasm_cbrtl(long double a) {
  return cbrtl(a);
}

WASM_EXPORT double      wasm_ceil(double a) {
  return ceil(a);
}
WASM_EXPORT float       wasm_ceilf(float a) {
  return ceilf(a);
}
WASM_EXPORT long double wasm_ceill(long double a) {
  return ceill(a);
}

WASM_EXPORT double      wasm_copysign(double a, double b) {
  return copysign(a, b);
}
WASM_EXPORT float       wasm_copysignf(float a, float b) {
  return copysignf(a, b);
}
WASM_EXPORT long double wasm_copysignl(long double a, long double b) {
  return copysignl(a, b);
}

WASM_EXPORT double      wasm_cos(double a) {
  return cos(a);
}
WASM_EXPORT float       wasm_cosf(float a) {
  return cosf(a);
}
WASM_EXPORT long double wasm_cosl(long double a) {
  return cosl(a);
}

WASM_EXPORT double      wasm_cosh(double a) {
  return cosh(a);
}
WASM_EXPORT float       wasm_coshf(float a) {
  return coshf(a);
}
WASM_EXPORT long double wasm_coshl(long double a) {
  return coshl(a);
}

WASM_EXPORT double      wasm_erf(double a) {
  return erf(a);
}
WASM_EXPORT float       wasm_erff(float a) {
  return erff(a);
}
WASM_EXPORT long double wasm_erfl(long double a) {
  return erfl(a);
}

WASM_EXPORT double      wasm_erfc(double a) {
  return erfc(a);
}
WASM_EXPORT float       wasm_erfcf(float a) {
  return erfcf(a);
}
WASM_EXPORT long double wasm_erfcl(long double a) {
  return erfcl(a);
}

WASM_EXPORT double      wasm_exp(double a) {
  return exp(a);
}
WASM_EXPORT float       wasm_expf(float a) {
  return expf(a);
}
WASM_EXPORT long double wasm_expl(long double a) {
  return expl(a);
}

WASM_EXPORT double      wasm_exp2(double a) {
  return exp2(a);
}
WASM_EXPORT float       wasm_exp2f(float a) {
  return exp2f(a);
}
WASM_EXPORT long double wasm_exp2l(long double a) {
  return exp2l(a);
}

WASM_EXPORT double      wasm_expm1(double a) {
  return expm1(a);
}
WASM_EXPORT float       wasm_expm1f(float a) {
  return expm1f(a);
}
WASM_EXPORT long double wasm_expm1l(long double a) {
  return expm1l(a);
}

WASM_EXPORT double      wasm_fabs(double a) {
  return fabs(a);
}
WASM_EXPORT float       wasm_fabsf(float a) {
  return fabsf(a);
}
WASM_EXPORT long double wasm_fabsl(long double a) {
  return fabsl(a);
}

WASM_EXPORT double      wasm_fdim(double a, double b) {
  return fdim(a, b);
}
WASM_EXPORT float       wasm_fdimf(float a, float b) {
  return fdimf(a, b);
}
WASM_EXPORT long double wasm_fdiml(long double a, long double b) {
  return fdiml(a, b);
}

WASM_EXPORT double      wasm_floor(double a) {
  return floor(a);
}
WASM_EXPORT float       wasm_floorf(float a) {
  return floorf(a);
}
WASM_EXPORT long double wasm_floorl(long double a) {
  return floorl(a);
}

WASM_EXPORT double      wasm_fma(double a, double b, double c) {
  return fma(a, b, c);
}
WASM_EXPORT float       wasm_fmaf(float a, float b, float c) {
  return fmaf(a, b, c);
}
WASM_EXPORT long double wasm_fmal(long double a, long double b, long double c) {
  return fmal(a, b, c);
}

WASM_EXPORT double      wasm_fmax(double a, double b) {
  return fmax(a, b);
}
WASM_EXPORT float       wasm_fmaxf(float a, float b) {
  return fmaxf(a, b);
}
WASM_EXPORT long double wasm_fmaxl(long double a, long double b) {
  return fmaxl(a, b);
}

WASM_EXPORT double      wasm_fmin(double a, double b) {
  return fmin(a, b);
}
WASM_EXPORT float       wasm_fminf(float a, float b) {
  return fminf(a, b);
}
WASM_EXPORT long double wasm_fminl(long double a, long double b) {
  return fminl(a, b);
}

WASM_EXPORT double      wasm_fmod(double a, double b) {
  return fmod(a, b);
}
WASM_EXPORT float       wasm_fmodf(float a, float b) {
  return fmodf(a, b);
}
WASM_EXPORT long double wasm_fmodl(long double a, long double b) {
  return fmodl(a, b);
}

WASM_EXPORT double      wasm_frexp(double a, int * b) {
  return frexp(a, b);
}
WASM_EXPORT float       wasm_frexpf(float a, int * b) {
  return frexpf(a, b);
}
WASM_EXPORT long double wasm_frexpl(long double a, int * b) {
  return frexpl(a, b);
}

WASM_EXPORT double      wasm_hypot(double a, double b) {
  return hypot(a, b);
}
WASM_EXPORT float       wasm_hypotf(float a, float b) {
  return hypotf(a, b);
}
WASM_EXPORT long double wasm_hypotl(long double a, long double b) {
  return hypotl(a, b);
}

WASM_EXPORT int         wasm_ilogb(double a) {
  return ilogb(a);
}
WASM_EXPORT int         wasm_ilogbf(float a) {
  return ilogbf(a);
}
WASM_EXPORT int         wasm_ilogbl(long double a) {
  return ilogbl(a);
}

WASM_EXPORT double      wasm_ldexp(double a, int b) {
  return ldexp(a, b);
}
WASM_EXPORT float       wasm_ldexpf(float a, int b) {
  return ldexpf(a, b);
}
WASM_EXPORT long double wasm_ldexpl(long double a, int b) {
  return ldexpl(a, b);
}

WASM_EXPORT double      wasm_lgamma(double a) {
  return lgamma(a);
}
WASM_EXPORT float       wasm_lgammaf(float a) {
  return lgammaf(a);
}
WASM_EXPORT long double wasm_lgammal(long double a) {
  return lgammal(a);
}

WASM_EXPORT long long   wasm_llrint(double a) {
  return llrint(a);
}
WASM_EXPORT long long   wasm_llrintf(float a) {
  return llrintf(a);
}
WASM_EXPORT long long   wasm_llrintl(long double a) {
  return llrintl(a);
}

WASM_EXPORT long long   wasm_llround(double a) {
  return llround(a);
}
WASM_EXPORT long long   wasm_llroundf(float a) {
  return llroundf(a);
}
WASM_EXPORT long long   wasm_llroundl(long double a) {
  return llroundl(a);
}

WASM_EXPORT double      wasm_log(double a) {
  return log(a);
}
WASM_EXPORT float       wasm_logf(float a) {
  return logf(a);
}
WASM_EXPORT long double wasm_logl(long double a) {
  return logl(a);
}

WASM_EXPORT double      wasm_log10(double a) {
  return log10(a);
}
WASM_EXPORT float       wasm_log10f(float a) {
  return log10f(a);
}
WASM_EXPORT long double wasm_log10l(long double a) {
  return log10l(a);
}

WASM_EXPORT double      wasm_log1p(double a) {
  return log1p(a);
}
WASM_EXPORT float       wasm_log1pf(float a) {
  return log1pf(a);
}
WASM_EXPORT long double wasm_log1pl(long double a) {
  return log1pl(a);
}

WASM_EXPORT double      wasm_log2(double a) {
  return log2(a);
}
WASM_EXPORT float       wasm_log2f(float a) {
  return log2f(a);
}
WASM_EXPORT long double wasm_log2l(long double a) {
  return log2l(a);
}

WASM_EXPORT double      wasm_logb(double a) {
  return logb(a);
}
WASM_EXPORT float       wasm_logbf(float a) {
  return logbf(a);
}
WASM_EXPORT long double wasm_logbl(long double a) {
  return logbl(a);
}

WASM_EXPORT long        wasm_lrint(double a) {
  return lrint(a);
}
WASM_EXPORT long        wasm_lrintf(float a) {
  return lrintf(a);
}
WASM_EXPORT long        wasm_lrintl(long double a) {
  return lrintl(a);
}

WASM_EXPORT long        wasm_lround(double a) {
  return lround(a);
}
WASM_EXPORT long        wasm_lroundf(float a) {
  return lroundf(a);
}
WASM_EXPORT long        wasm_lroundl(long double a) {
  return lroundl(a);
}

WASM_EXPORT double      wasm_modf(double a, double * b) {
  return modf(a, b);
}
WASM_EXPORT float       wasm_modff(float a, float * b) {
  return modff(a, b);
}
WASM_EXPORT long double wasm_modfl(long double a, long double * b) {
  return modfl(a, b);
}

WASM_EXPORT double      wasm_nan(const char * a) {
  return nan(a);
}
WASM_EXPORT float       wasm_nanf(const char * a) {
  return nanf(a);
}
WASM_EXPORT long double wasm_nanl(const char * a) {
  return nanl(a);
}

WASM_EXPORT double      wasm_nearbyint(double a) {
  return nearbyint(a);
}
WASM_EXPORT float       wasm_nearbyintf(float a) {
  return nearbyintf(a);
}
WASM_EXPORT long double wasm_nearbyintl(long double a) {
  return nearbyintl(a);
}

WASM_EXPORT double      wasm_nextafter(double a, double b) {
  return nextafter(a, b);
}
WASM_EXPORT float       wasm_nextafterf(float a, float b) {
  return nextafterf(a, b);
}
WASM_EXPORT long double wasm_nextafterl(long double a, long double b) {
  return nextafterl(a, b);
}

WASM_EXPORT double      wasm_nexttoward(double a, long double b) {
  return nexttoward(a, b);
}
WASM_EXPORT float       wasm_nexttowardf(float a, long double b) {
  return nexttowardf(a, b);
}
WASM_EXPORT long double wasm_nexttowardl(long double a, long double b) {
  return nexttowardl(a, b);
}

WASM_EXPORT double      wasm_pow(double a, double b) {
  return pow(a, b);
}
WASM_EXPORT float       wasm_powf(float a, float b) {
  return powf(a, b);
}
WASM_EXPORT long double wasm_powl(long double a, long double b) {
  return powl(a, b);
}

WASM_EXPORT double      wasm_remainder(double a, double b) {
  return remainder(a, b);
}
WASM_EXPORT float       wasm_remainderf(float a, float b) {
  return remainderf(a, b);
}
WASM_EXPORT long double wasm_remainderl(long double a, long double b) {
  return remainderl(a, b);
}

WASM_EXPORT double      wasm_remquo(double a, double b, int * c) {
  return remquo(a, b, c);
}
WASM_EXPORT float       wasm_remquof(float a, float b, int * c) {
  return remquof(a, b, c);
}
WASM_EXPORT long double wasm_remquol(long double a, long double b, int * c) {
  return remquol(a, b, c);
}

WASM_EXPORT double      wasm_rint(double a) {
  return rint(a);
}
WASM_EXPORT float       wasm_rintf(float a) {
  return rintf(a);
}
WASM_EXPORT long double wasm_rintl(long double a) {
  return rintl(a);
}

WASM_EXPORT double      wasm_round(double a) {
  return round(a);
}
WASM_EXPORT float       wasm_roundf(float a) {
  return roundf(a);
}
WASM_EXPORT long double wasm_roundl(long double a) {
  return roundl(a);
}

WASM_EXPORT double      wasm_scalbln(double a, long b) {
  return scalbln(a, b);
}
WASM_EXPORT float       wasm_scalblnf(float a, long b) {
  return scalblnf(a, b);
}
WASM_EXPORT long double wasm_scalblnl(long double a, long b) {
  return scalblnl(a, b);
}

WASM_EXPORT double      wasm_scalbn(double a, int b) {
  return scalbn(a, b);
}
WASM_EXPORT float       wasm_scalbnf(float a, int b) {
  return scalbnf(a, b);
}
WASM_EXPORT long double wasm_scalbnl(long double a, int b) {
  return scalbnl(a, b);
}

WASM_EXPORT double      wasm_sin(double a) {
  return sin(a);
}
WASM_EXPORT float       wasm_sinf(float a) {
  return sinf(a);
}
WASM_EXPORT long double wasm_sinl(long double a) {
  return sinl(a);
}

WASM_EXPORT double      wasm_sinh(double a) {
  return sinh(a);
}
WASM_EXPORT float       wasm_sinhf(float a) {
  return sinhf(a);
}
WASM_EXPORT long double wasm_sinhl(long double a) {
  return sinhl(a);
}

WASM_EXPORT double      wasm_sqrt(double a) {
  return sqrt(a);
}
WASM_EXPORT float       wasm_sqrtf(float a) {
  return sqrtf(a);
}
WASM_EXPORT long double wasm_sqrtl(long double a) {
  return sqrtl(a);
}

WASM_EXPORT double      wasm_tan(double a) {
  return tan(a);
}
WASM_EXPORT float       wasm_tanf(float a) {
  return tanf(a);
}
WASM_EXPORT long double wasm_tanl(long double a) {
  return tanl(a);
}

WASM_EXPORT double      wasm_tanh(double a) {
  return tanh(a);
}
WASM_EXPORT float       wasm_tanhf(float a) {
  return tanhf(a);
}
WASM_EXPORT long double wasm_tanhl(long double a) {
  return tanhl(a);
}

WASM_EXPORT double      wasm_tgamma(double a) {
  return tgamma(a);
}
WASM_EXPORT float       wasm_tgammaf(float a) {
  return tgammaf(a);
}
WASM_EXPORT long double wasm_tgammal(long double a) {
  return tgammal(a);
}

WASM_EXPORT double      wasm_trunc(double a) {
  return trunc(a);
}
WASM_EXPORT float       wasm_truncf(float a) {
  return truncf(a);
}
WASM_EXPORT long double wasm_truncl(long double a) {
  return truncl(a);
}

WASM_EXPORT double      wasm_j0(double a) {
  return j0(a);
}
WASM_EXPORT double      wasm_j1(double a) {
  return j1(a);
}
WASM_EXPORT double      wasm_jn(int a, double b) {
  return jn(a, b);
}

WASM_EXPORT double      wasm_y0(double a) {
  return y0(a);
}
WASM_EXPORT double      wasm_y1(double a) {
  return y1(a);
}
WASM_EXPORT double      wasm_yn(int a, double b) {
  return yn(a, b);
}

WASM_EXPORT double      wasm_drem(double a, double b) {
  return drem(a, b);
}
WASM_EXPORT float       wasm_dremf(float a, float b) {
  return dremf(a, b);
}

WASM_EXPORT int         wasm_finite(double a) {
  return finite(a);
}
WASM_EXPORT int         wasm_finitef(float a) {
  return finitef(a);
}

WASM_EXPORT double      wasm_scalb(double a, double b) {
  return scalb(a, b);
}
WASM_EXPORT float       wasm_scalbf(float a, float b) {
  return scalbf(a, b);
}

WASM_EXPORT double      wasm_significand(double a) {
  return significand(a);
}
WASM_EXPORT float       wasm_significandf(float a) {
  return significandf(a);
}

WASM_EXPORT double      wasm_lgamma_r(double a, int* b) {
  return lgamma_r(a, b);
}
WASM_EXPORT float       wasm_lgammaf_r(float a, int* b) {
  return lgammaf_r(a, b);
}

WASM_EXPORT float       wasm_j0f(float a) {
  return j0f(a);
}
WASM_EXPORT float       wasm_j1f(float a) {
  return j1f(a);
}
WASM_EXPORT float       wasm_jnf(int a, float b) {
  return jnf(a, b);
}

WASM_EXPORT float       wasm_y0f(float a) {
  return y0f(a);
}
WASM_EXPORT float       wasm_y1f(float a) {
  return y1f(a);
}
WASM_EXPORT float       wasm_ynf(int a, float b) {
  return ynf(a, b);
}

WASM_EXPORT long double wasm_lgammal_r(long double a, int* b) {
  return lgammal_r(a, b);
}

WASM_EXPORT void        wasm_sincos(double a, double* b, double* c) {
  sincos(a, b, c);
}
WASM_EXPORT void        wasm_sincosf(float a, float* b, float* c) {
  sincosf(a, b, c);
}
WASM_EXPORT void        wasm_sincosl(long double a, long double* b, long double* c) {
  sincosl(a, b, c);
}

WASM_EXPORT double      wasm_exp10(double a) {
  return exp10(a);
}
WASM_EXPORT float       wasm_exp10f(float a) {
  return exp10f(a);
}
WASM_EXPORT long double wasm_exp10l(long double a) {
  return exp10l(a);
}

WASM_EXPORT double      wasm_pow10(double a) {
  return pow10(a);
}
WASM_EXPORT float       wasm_pow10f(float a) {
  return pow10f(a);
}
WASM_EXPORT long double wasm_pow10l(long double a) {
  return pow10l(a);
}