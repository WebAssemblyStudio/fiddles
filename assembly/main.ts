declare function logf(val: f64): void;
// declare function logi(val: i32): void;
declare function logSin(arg: f64, x: f32): void;

var rempio2f_y: f64 = 0;

var volatile32: f32;
var volatile64: f64;

@inline /** @internal */
function FORCE_EVAL<T>(expr: T): void {
  if (sizeof<T>() == 4) {
    volatile32 = <f32>expr;
  } else if (sizeof<T>() == 8) {
    volatile64 = <f64>expr;
  }
}

@inline /** @internal */
function pio2_large_quot(x: f32, u: i32): i32 { // see: jdh8/metallic/blob/master/src/math/float/rem_pio2f.c
  const pi_2_65 = reinterpret<f64>(0x3BF921FB54442D18); // 8.51530395021638647334e-20

  const bits: u64[] = [
    0xA2F9836E4E441529,
    0xFC2757D1F534DDC0,
    0xDB6295993C439041,
    0xFE5163ABDEBBC561
  ];

  var offset = (u >> 23) - 152;
  var index  = offset >> 6;
  var shift  = offset & 63;

  var b0 = unchecked(bits[index + 0]);
  var b1 = unchecked(bits[index + 1]);
  var lo: u64;

  if (shift > 32) {
    let b2 = unchecked(bits[index + 2]);
    lo  = b2 >> (96 - shift);
    lo |= b1 << (shift - 32);
  } else {
    lo = b1 >> (32 - shift);
  }

  var hi = (b1 >> (64 - shift)) | (b0 << shift);
  var mantissa: u64 = (u & 0x007FFFFF) | 0x00800000;
  var product: u64 = mantissa * hi + ((mantissa * lo) >> 32);
  var r: i64 = product << 2;
  // var q: i32 = <i32>(product >> 62) + <i32>(r < 0);
  var q: i32 = <i32>((product >> 62) + (r >>> 63));
  rempio2f_y = copysign<f64>(pi_2_65, x) * <f64>r;
  return q;
}

@inline /** @internal */
function rempio2f(x: f32, u: u32, sign: i32): i32 { // see: jdh8/metallic/blob/master/src/math/float/rem_pio2f.c
  const pi2hi = reinterpret<f64>(0x3FF921FB50000000); // 1.57079631090164184570
  const pi2lo = reinterpret<f64>(0x3E5110B4611A6263); // 1.58932547735281966916e-8
  const _2_pi = reinterpret<f64>(0x3FE45F306DC9C883); // 0.63661977236758134308

  if (u < 0x4DC90FDB) {
    let q = nearest(x * _2_pi);
    rempio2f_y = x - q * pi2hi - q * pi2lo;
    return <i32>q;
  }

  var q = pio2_large_quot(x, u);
  return select(-q, q, sign);
}

/* |sin(x)/x - s(x)| < 2**-37.5 (~[-4.89e-12, 4.824e-12]). */
@inline function __sindf(x: f64): f32 {
  
  const S1 = reinterpret<f64>(0xBFC5555554CBAC77); // -0x15555554cbac77.0p-55
  const S2 = reinterpret<f64>(0x3F811110896EFBB2); //  0x111110896efbb2.0p-59
  const S3 = reinterpret<f64>(0xBF2A00F9E2CAE774); // -0x1a00f9e2cae774.0p-65
  const S4 = reinterpret<f64>(0x3EC6CD878C3B46A7); //  0x16cd878c3b46a7.0p-71

  var z = x * x;
  var w = z * z;
  var r = S3 + z * S4;
  var s = z * x;
	return <f32>((x + s * (S1 + z * S2)) + s * w * r);
  
  // var x2 = x * x;
  // var x4 = x2 * x2;
  // /* evaluate polynomial using a mix of Estrin's and Horner's scheme */
  // return <f32>(((2.7181216275479732e-6 * x2 - 1.9839312269456257e-4) * x4 +
  //         (8.3333293048425631e-3 * x2 - 1.6666666640797048e-1)) * x2 * x + x);
}

/* |cos(x) - c(x)| < 2**-34.1 (~[-5.37e-11, 5.295e-11]). */
@inline function __cosdf(x: f64): f32 {
  const C0 = reinterpret<f64>(0xBFDFFFFFFD0C5E81); // -0x1ffffffd0c5e81.0p-54
  const C1 = reinterpret<f64>(0x3FA55553E1053A42); //  0x155553e1053a42.0p-57
  const C2 = reinterpret<f64>(0xBF56C087E80F1E27); // -0x16c087e80f1e27.0p-62
  const C3 = reinterpret<f64>(0x3EF99342E0EE5069); //  0x199342e0ee5069.0p-68

	var z = x * x;
	var w = z * z;
	var r = C2 + z * C3;
	return <f32>(((1 + z * C0) + w * C1) + (w * z) * r);
}


function cosf(x: f32): f32 {
  const c1pio2 = reinterpret<f64>(0x3FF921FB54442D18); // M_PI_2 * 1
  const c2pio2 = reinterpret<f64>(0x400921FB54442D18); // M_PI_2 * 2
  const c3pio2 = reinterpret<f64>(0x4012D97C7F3321D2); // M_PI_2 * 3
  const c4pio2 = reinterpret<f64>(0x401921FB54442D18); // M_PI_2 * 4
  const Ox1p120f = reinterpret<f32>(0x7b800000);       // 2 ** 120

	var ix = reinterpret<u32>(x);
  var sign = ix >> 31;
  ix &= 0x7FFFFFFF;

	if (ix <= 0x3f490fda) {  /* |x| ~<= pi/4 */
		if (ix < 0x39800000) {  /* |x| < 2**-12 */
			/* raise inexact if x != 0 */
			FORCE_EVAL(x + Ox1p120f);
			return 1;
		}
		return __cosdf(x);
	}
	if (ix <= 0x407b53d1) {  /* |x| ~<= 5*pi/4 */
		if (ix > 0x4016cbe3)  /* |x|  ~> 3*pi/4 */
			return -__cosdf(sign ? x + c2pio2 : x - c2pio2);
		else {
			return sign ? __sindf(x + c1pio2) : __sindf(c1pio2 - x);
		}
	}
	if (ix <= 0x40e231d5) {  /* |x| ~<= 9*pi/4 */
		if (ix > 0x40afeddf)  /* |x| ~> 7*pi/4 */
			return __cosdf(sign ? x + c4pio2 : x - c4pio2);
		else {
			return sign ? __sindf(-x - c3pio2) : __sindf(x - c3pio2);
		}
	}

	/* cos(Inf or NaN) is NaN */
	if (ix >= 0x7f800000) return x - x;

	/* general argument reduction needed */
	var n = rempio2f(x, ix, sign);
  var y = rempio2f_y;

	switch (n & 3) {
	  case 0:  return  __cosdf(y);
	  case 1:  return  __sindf(-y);
	  case 2:  return -__cosdf(y);
	  default: return  __sindf(y);
	}
}


function sinf(x: f32): f32 {
  const s1pio2 = reinterpret<f64>(0x3FF921FB54442D18); // M_PI_2 * 1
  const s2pio2 = reinterpret<f64>(0x400921FB54442D18); // M_PI_2 * 2
  const s3pio2 = reinterpret<f64>(0x4012D97C7F3321D2); // M_PI_2 * 3
  const s4pio2 = reinterpret<f64>(0x401921FB54442D18); // M_PI_2 * 4
  // const Ox1p120f = reinterpret<f32>(0x7b800000);       // 2 ** 120

  var ix = reinterpret<u32>(x);
  var sign = ix >> 31;
  ix &= 0x7FFFFFFF;

  if (ix <= 0x3f490fda) { /* |x| ~<= pi/4 */
    if (ix < 0x39800000) {  /* |x| < 2**-12 */
			/* raise inexact if x!=0 and underflow if subnormal */
			// FORCE_EVAL(ix < 0x00800000 ? x / Ox1p120f : x + Ox1p120f);
			return x;
		}
		return __sindf(x);
  }

  if (ix <= 0x407b53d1) {  /* |x| ~<= 5*pi/4 */
    if (ix <= 0x4016cbe3) {  /* |x| ~<= 3pi/4 */
			return sign ? -__cosdf(x + s1pio2) : __cosdf(x - s1pio2);
		}
		return __sindf(-(sign ? (x + s2pio2) : (x - s2pio2)));
  }

  if (ix <= 0x40e231d5) {  /* |x| ~<= 9*pi/4 */
		if (ix <= 0x40afeddf) {  /* |x| ~<= 7*pi/4 */
			return sign ? __cosdf(x + s3pio2) : -__cosdf(x - s3pio2);
		}
		return __sindf(sign ? x + s4pio2 : x - s4pio2);
	}

  /* sin(Inf or NaN) is NaN */
	if (ix >= 0x7f800000) return x - x;

  var n = rempio2f(x, ix, sign);
  var y = rempio2f_y;

  var t = n & 1 ? __cosdf(y) : __sindf(y);
  return n & 2 ? -t : t;
}

logSin(0.0, sinf(0.0));
logSin(1.0, sinf(1.0));
logSin(-1.0, sinf(-1.0));
logSin(<f32>Math.PI / 2, sinf(<f32>Math.PI / 2));
logSin(<f32>-Math.PI / 2, sinf(<f32>-Math.PI / 2));
logSin(<f32>Math.PI, sinf(<f32>Math.PI));
logSin(<f32>Math.PI * 100, sinf(<f32>Math.PI * 100));
logSin(<f32>Math.PI * 10000 + 1000, sinf(<f32>Math.PI * 10000 + 1000));
logSin(<f32>(Math.PI * 10000 + Math.PI / 2.0), sinf(<f32>(Math.PI * 10000 + Math.PI / 2.0)));
logSin(<f32>(-Math.PI * 10000 + Math.PI / 2.0), sinf(<f32>(-Math.PI * 10000 + Math.PI / 2.0)));
logSin(<f32>(i32.MAX_VALUE * Math.PI * 10000), sinf(<f32>(i32.MAX_VALUE * Math.PI * 10000)));
logSin(<f32>(-i32.MAX_VALUE * Math.PI * 10000), sinf(<f32>(-i32.MAX_VALUE * Math.PI * 10000)));

export function bench(): f64 {
  var acc = 0.0;
  for (let i = 0; i < 421657440; i++) {
  // for (let i: f64 = 0; i < 0.5; i += (1.0 / 421657440)) {
    acc += sinf(<f32>i);
  }
  return acc;
}

// -111.06402420936791
