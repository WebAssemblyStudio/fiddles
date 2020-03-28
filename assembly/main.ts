
@inline
function log2f(x: f64): f64 {
  const
    log2e = 1.44269504088896340736,
    c0 = 0.9999999993072205474,
    c1 = 0.3333340818599626478,
    c2 = 0.1998737838945025914,
    c3 = 0.1496325726858180278;

  let i = reinterpret<i64>(x);
  let exponent = (i - 0x3FE6A09E667F3BCD) >> 52;
  x = reinterpret<f64>(i - (exponent << 52));
  x = (x - 1) / (x + 1);
  let xx = x * x;
  let y = x * (c0 + c1 * xx + (c2 + c3 * xx) * (xx * xx));
  return (2 * log2e) * y + <f64>exponent;
}

@inline
function exp2f(x: f64): f64 {
  const 
    c0 = 6.931471880289532425e-1,
    c1 = 2.402265108421173406e-1,
    c2 = 5.550357105498874537e-2,
    c3 = 9.618030771171497658e-3,
    c4 = 1.339086685300950937e-3,
    c5 = 1.546973499989028719e-4;

  if (x < -1022) return 0;
  if (x >= 1024) return Infinity;
  
  let n = nearest(x);
  x -= n;
  let xx = x * x;
  let y = 1 + x * (c0 + c1 * x + (c2 + c3 * x) * xx + (c4 + c5 * x) * (xx * xx));
  return reinterpret<f64>(reinterpret<i64>(y) + (<i64>n << 52));
}

export function powf_new(x: f32, y: f32): f32 {
  let sign: u32 = 0;
  let iy = reinterpret<i32>(y);
  let ix = reinterpret<i32>(x);
  if (y == 0) return 1;
  if (isNaN(x) || isNaN(y)) {
    return NaN;
  }
  if ((ix >>> 31) && nearest(y) == y) {
    x = -x;
    ix &= 0x7FFFFFFF;
    sign = u32(nearest(y * 0.5) != y * 0.5) << 31;
  }
  let m: u32;
  if (ix == 0x3F800000) { // x == 1
    m = (iy & 0x7FFFFFFF) == 0x7F800000 ? 0x7FC00000 : 0x3F800000;
  } else if (x == 0) {
    m = iy >>> 31 ? 0x7F800000 : 0;
  } else if ((ix & 0x7FFFFFFF) == 0x7F800000) {
    m = iy >>> 31 ? 0 : 0x7F800000;
  } else if (ix >>> 31) {
    return NaN;
  } else {
    m = reinterpret<u32>(<f32>exp2f(<f64>y * log2f(x)));
  }
  return reinterpret<f32>(m | sign);
}

export function powf_old(x: f32, y: f32): f32 {
  return Mathf.pow(x, y);
}
