

/* Inverse hyperbolic tangent restricted to [-c, c], where
 *
 *     √2 - 1                  1 + c
 * c = ------  the solution to ----- = √2.
 *     √2 + 1,                 1 - c
 */
@inline
function kernel_atanhf_(x: f64): f64 {
  const
    c0 = 0.9999999993072205474,
    c1 = 0.3333340818599626478,
    c2 = 0.1998737838945025914,
    c3 = 0.1496325726858180278;
  let xx = x * x;
  return x * (c0 + c1 * xx + (c2 + c3 * xx) * (xx * xx));
}

/* Restriction of (x -> 2^x - 1) to [-0.5, 0.5] */
@inline
function kernel_exp2f_(x: f64): f64 {
  const 
    c0 = 6.931471880289532425e-1,
    c1 = 2.402265108421173406e-1,
    c2 = 5.550357105498874537e-2,
    c3 = 9.618030771171497658e-3,
    c4 = 1.339086685300950937e-3,
    c5 = 1.546973499989028719e-4;
  let xx = x * x;
  return x * (c0 + c1 * x + (c2 + c3 * x) * xx + (c4 + c5 * x) * (xx * xx));
}

@inline
function shift_(x: f64, n: i64): f64 {
  return reinterpret<f64>(reinterpret<i64>(x) + (n << 52));
}

@inline
function log2f_(x: f64): f64 {
  const log2e = 1.44269504088896340736;
  let i = reinterpret<i64>(x);
  let exponent = (i - 0x3FE6A09E667F3BCD) >> 52;
  x = reinterpret<f64>(i - (exponent << 52));
  return 2 * log2e * kernel_atanhf_((x - 1) / (x + 1)) + <f64>exponent;
}

@inline
function exp2f_(x: f64): f64 {
  if (x < -1022) return 0;
  if (x >= 1024) return x * Infinity;

  let n = nearest(x);
  let y = 1 + kernel_exp2f_(x - n);
  return shift_(y, <i64>n);
}

@inline
function unsigned_(x: f32, y: f32, ux: u32, uy: u32): f32 {
  if (x == 1) return 1;
  // if (x == 0) return uy >>> 31 ? Infinity : 0;
  // if (abs(x) == Infinity) return uy >>> 31 ? 0 : Infinity;
  // if (ux >>> 31) return NaN;

  return <f32>exp2f_(y as f64 * log2f_(x as f64));
}

export function powf_new(x: f32, y: f32): f32 {
  let sign: u32 = 0;
  let hx = reinterpret<u32>(x);
  let hy = reinterpret<u32>(y);
  var ix = hx & 0x7FFFFFFF;
  var iy = hy & 0x7FFFFFFF;
  if (iy == 0) return 1;
  if (ix > 0x7F800000 || iy > 0x7F800000) return x + y; // NaN if either arg is NaN
  if (iy == 0x3F800000) return hy >= 0 ? x : 1.0 / x;
  if (hy == 0x40000000) return x * x;
  if (hy == 0x3F000000) {
    if (hx >= 0) return sqrt<f32>(x);
  }
  var ax = abs<f32>(x);
  var z: f32;
  var yisint = 0;
  if (ix == 0x7F800000 || ix == 0 || ix == 0x3F800000) {
    z = ax;
    if (hy < 0) z = 1.0 / z;
    if (hx < 0) {
      if (((ix - 0x3F800000) | yisint) == 0) {
        let d = z - z;
        z = d / d;
      }
      else if (yisint == 1) z = -z;
    }
    return z;
  }
  var sn = <f32>1.0;
  if (hx < 0) {
    if (yisint == 0) {
      let d = x - x;
      return d / d;
    }
    if (yisint == 1) sn = -1.0;
  }
  // if (Mathf.signbit(x) && nearest(y) == y) {
  if ((hx >>> 31) && nearest(y) == y) {
    x = -x;
    sign = -(nearest(y * 0.5) != y * 0.5);
  }
  return copysign(unsigned_(x, y, hx, hy), reinterpret<f32>(sign));
}

export function powf_old(x: f32, y: f32): f32 {
  return Mathf.pow(x, y);
}
