/* Lookup data for powf. See: https://git.musl-libc.org/cgit/musl/tree/src/math/powf.c */

@lazy const EXP2F_TABLE_BITS = 5;

// @ts-ignore: decorator
@lazy const POWF_LOG2_TABLE_BITS = 4;
// @ts-ignore: decorator
@lazy const POWF_SCALE_BITS = 0;
// @ts-ignore: decorator
@lazy const POWF_SCALE = <f64>(1 << POWF_SCALE_BITS);

// TODO: remove this and use log2_data_tab instead
// @ts-ignore: decorator
@lazy const powf_log2_data_tab: f64[] = [
  reinterpret<f64>(0x3FF661EC79F8F3BE), reinterpret<f64>(0xBFDEFEC65B963019) * POWF_SCALE,
  reinterpret<f64>(0x3FF571ED4AAF883D), reinterpret<f64>(0xBFDB0B6832D4FCA4) * POWF_SCALE,
  reinterpret<f64>(0x3FF49539F0F010B0), reinterpret<f64>(0xBFD7418B0A1FB77B) * POWF_SCALE,
  reinterpret<f64>(0x3FF3C995B0B80385), reinterpret<f64>(0xBFD39DE91A6DCF7B) * POWF_SCALE,
  reinterpret<f64>(0x3FF30D190C8864A5), reinterpret<f64>(0xBFD01D9BF3F2B631) * POWF_SCALE,
  reinterpret<f64>(0x3FF25E227B0B8EA0), reinterpret<f64>(0xBFC97C1D1B3B7AF0) * POWF_SCALE,
  reinterpret<f64>(0x3FF1BB4A4A1A343F), reinterpret<f64>(0xBFC2F9E393AF3C9F) * POWF_SCALE,
  reinterpret<f64>(0x3FF12358F08AE5BA), reinterpret<f64>(0xBFB960CBBF788D5C) * POWF_SCALE,
  reinterpret<f64>(0x3FF0953F419900A7), reinterpret<f64>(0xBFAA6F9DB6475FCE) * POWF_SCALE,
  reinterpret<f64>(0x3FF0000000000000), 0,
  reinterpret<f64>(0x3FEE608CFD9A47AC), reinterpret<f64>(0x3FB338CA9F24F53D) * POWF_SCALE,
  reinterpret<f64>(0x3FECA4B31F026AA0), reinterpret<f64>(0x3FC476A9543891BA) * POWF_SCALE,
  reinterpret<f64>(0x3FEB2036576AFCE6), reinterpret<f64>(0x3FCE840B4AC4E4D2) * POWF_SCALE,
  reinterpret<f64>(0x3FE9C2D163A1AA2D), reinterpret<f64>(0x3FD40645F0C6651C) * POWF_SCALE,
  reinterpret<f64>(0x3FE886E6037841ED), reinterpret<f64>(0x3FD88E9C2C1B9FF8) * POWF_SCALE,
  reinterpret<f64>(0x3FE767DCF5534862), reinterpret<f64>(0x3FDCE0A44EB17BCC) * POWF_SCALE
];

@lazy export const exp2f_data_tab: u64[] = [
  /* tab[i] = uint(2^(i/N)) - (i << 52-BITS)
    used for computing 2^(k/N) for an int |k| < 150 N as
    double(tab[k%N] + (k << 52-BITS)) */
  0x3ff0000000000000, 0x3fefd9b0d3158574, 0x3fefb5586cf9890f, 0x3fef9301d0125b51,
  0x3fef72b83c7d517b, 0x3fef54873168b9aa, 0x3fef387a6e756238, 0x3fef1e9df51fdee1,
  0x3fef06fe0a31b715, 0x3feef1a7373aa9cb, 0x3feedea64c123422, 0x3feece086061892d,
  0x3feebfdad5362a27, 0x3feeb42b569d4f82, 0x3feeab07dd485429, 0x3feea47eb03a5585,
  0x3feea09e667f3bcd, 0x3fee9f75e8ec5f74, 0x3feea11473eb0187, 0x3feea589994cce13,
  0x3feeace5422aa0db, 0x3feeb737b0cdc5e5, 0x3feec49182a3f090, 0x3feed503b23e255d,
  0x3feee89f995ad3ad, 0x3feeff76f2fb5e47, 0x3fef199bdd85529c, 0x3fef3720dcef9069,
  0x3fef5818dcfba487, 0x3fef7c97337b9b5f, 0x3fefa4afa2a490da, 0x3fefd0765b6e4540
];

// @ts-ignore: decorator
@inline function zeroinfnan(ux: u32): bool {
  return (ux << 1) - 1 >= (<u32>0x7f800000 << 1) - 1;
}

/* Returns 0 if not int, 1 if odd int, 2 if even int. The argument is
   the bit representation of a non-zero finite floating-point value. */
// @ts-ignore: decorator
@inline function checkint(iy: u32): i32 {
  var e = iy >> 23 & 0xFF;
  if (e < 0x7F     ) return 0;
  if (e > 0x7F + 23) return 2;
  e = 1 << (0x7F + 23 - e);
  if (iy & (e - 1)) return 0;
  if (iy &  e     ) return 1;
  return 2;
}

/* Subnormal input is normalized so ix has negative biased exponent.
   Output is multiplied by N (POWF_SCALE) if TOINT_INTRINICS is set. */
// @ts-ignore: decorator
@inline function log2_inline(ux: u32): f64 {
  const A0 = reinterpret<f64>(0x3FD27616C9496E0B); //  0x1.27616c9496e0bp-2
  const A1 = reinterpret<f64>(0xBFD71969A075C67A); // -0x1.71969a075c67ap-2
  const A2 = reinterpret<f64>(0x3FDEC70A6CA7BADD); //  0x1.ec70a6ca7baddp-2
  const A3 = reinterpret<f64>(0xBFE7154748BEF6C8); // -0x1.7154748bef6c8p-1
  const A4 = reinterpret<f64>(0x3FF71547652AB82B); //  0x1.71547652ab82bp+0
  const N_MASK = (1 << POWF_LOG2_TABLE_BITS) - 1;

  /* x = 2^k z; where z is in range [OFF,2*OFF] and exact.
    The range is split into N subintervals.
    The ith subinterval contains z and c is near its center.  */
  var tmp  = ux - 0x3F330000;
  var i    = <usize>((tmp >> (23 - POWF_LOG2_TABLE_BITS)) & N_MASK);
  var top  = tmp & 0xFF800000;
  var uz   = ux - top;
  var k    = <i32>(<i32>top >> 23);

  // @ts-ignore: cast
  const tab = powf_log2_data_tab.dataStart as usize;

  var invc = load<f64>(tab + (i << (1 + alignof<f64>())), 0 << alignof<f64>());
  var logc = load<f64>(tab + (i << (1 + alignof<f64>())), 1 << alignof<f64>());
  var z    = <f64>reinterpret<f32>(uz);

  // log2(x) = log1p(z/c-1)/ln2 + log2(c) + k
  var r  = z * invc - 1;
  var y0 = logc + <f64>k;

  // Pipelined polynomial evaluation to approximate log1p(r)/ln2.
  var y = A0 * r + A1;
  var p = A2 * r + A3;
  var q = A4 * r + y0;

  r *= r;
  q += p * r;
  y  = y * (r * r) + q;

  return y;
}

/* The output of log2 and thus the input of exp2 is either scaled by N
   (in case of fast toint intrinsics) or not.  The unscaled xd must be
   in [-1021,1023], sign_bias sets the sign of the result.  */
// @ts-ignore: decorator
@inline function exp2_inline(xd: f64, signBias: u32): f32 {
  const N      = 1 << EXP2F_TABLE_BITS;
  const N_MASK = N - 1;
  const shift  = reinterpret<f64>(0x4338000000000000) / N; // 0x1.8p+52

  const C0 = reinterpret<f64>(0x3FAC6AF84B912394); // 0x1.c6af84b912394p-5
  const C1 = reinterpret<f64>(0x3FCEBFCE50FAC4F3); // 0x1.ebfce50fac4f3p-3
  const C2 = reinterpret<f64>(0x3FE62E42FF0C52D6); // 0x1.62e42ff0c52d6p-1

  // x = k/N + r with r in [-1/(2N), 1/(2N)]
  var kd = <f64>(xd + shift);
  var ki = reinterpret<u64>(kd);
  var r  = xd - (kd - shift);
  var t: u64, z: f64, y: f64, s: f64;

  // exp2(x) = 2^(k/N) * 2^r ~= s * (C0*r^3 + C1*r^2 + C2*r + 1)
  // @ts-ignore: cast
  const tab = exp2f_data_tab.dataStart as usize;

  // exp2(x) = 2^(k/N) * 2^r ~= s * (C0*r^3 + C1*r^2 + C2*r + 1)
  t  = load<u64>(tab + ((<usize>ki & N_MASK) << alignof<u64>()));
  t += (ki + signBias) << (52 - EXP2F_TABLE_BITS);
  s  = reinterpret<f64>(t);
  z  = C0 * r + C1;
  y  = C2 * r + 1;
  y += z * (r * r);
  y *= s;
  return <f32>y;
}

@inline function xflowf(sign: u32, y: f32): f32 {
  return <f32>((sign ? -y : y) * y);
}

@inline function oflowf(sign: u32): f32 {
  return xflowf(sign, reinterpret<f32>(0x70000000)); // 0x1p97f
}

@inline function uflowf(sign: u32): f32 {
  return xflowf(sign, reinterpret<f32>(0x10000000)); // 0x1p-95f
}

export function powf_lut(x: f32, y: f32): f32 {
  const Ox1p23f     = reinterpret<f32>(0x4B000000); // 0x1p23f
  const UPPER_LIMIT = reinterpret<f64>(0x405FFFFFFFD1D571); // 0x1.fffffffd1d571p+6
  const LOWER_LIMIT = -150.0;
  const SIGN_BIAS   = 1 << (EXP2F_TABLE_BITS + 11);

  var signBias: u32 = 0;
  var ix = reinterpret<u32>(x);
  var iy = reinterpret<u32>(y);
  var ni = 0;

  if (i32(ix - 0x00800000 >= 0x7f800000 - 0x00800000) | (ni = i32(zeroinfnan(iy)))) {
    // Either (x < 0x1p-126 or inf or nan) or (y is 0 or inf or nan).
    if (ni) {
      if ((iy << 1) == 0) return 1.0;
      if (ix == 0x3F800000) return NaN; // // original: 1.0
      if ((ix << 1) > (<u32>0x7F800000 << 1) || (iy << 1) > <u32>(0x7F800000 << 1)) return x + y;
      if ((ix << 1) == (0x3F800000 << 1)) return NaN; // original: 1.0
      if (((ix << 1) < (0x3F800000 << 1)) == !(iy >> 31)) return 0; // |x| < 1 && y==inf or |x| > 1 && y==-inf.
      return y * y;
    }
    if (zeroinfnan(ix)) {
      let x2 = x * x;
      if ((ix & 0x80000000) && checkint(iy) == 1) x2 = -x2;
      return iy & 0x80000000 ? 1 / x2 : x2;
    }
    // x and y are non-zero finite.
    if (ix >> 31) {
      // Finite x < 0.
      let yint = checkint(iy);
      if (yint == 0) return (x - x) / (x - x);
      if (yint == 1) signBias = SIGN_BIAS;
      ix &= 0x7FFFFFFF;
    }
    if (ix < 0x00800000) {
      // Normalize subnormal x so exponent becomes negative.
      ix = reinterpret<u32>(x * Ox1p23f);
      ix &= 0x7FFFFFFF;
      ix -= 23 << 23;
    }
  }
  var logx = log2_inline(ix);
  var ylogx = y * logx; // cannot overflow, y is single prec.
  if ((reinterpret<u64>(ylogx) >> 47 & 0xFFFF) >= 0x80BF) {
    // |y * log(x)| >= 126
    if (ylogx  > UPPER_LIMIT) return oflowf(signBias); // overflow
    if (ylogx <= LOWER_LIMIT) return uflowf(signBias); // underflow
  }
  return exp2_inline(ylogx, signBias);
}