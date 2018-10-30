

export function original(): f64 {
  var acc = 0.0;
  for (let x = 1e-60; x < 1e60; x *= 1.00001) {
    acc += Math.exp(x) * 1e-60;
  }
  return acc;
}

export function newVersion(): f64 {
  var acc = 0.0;
  for (let x = 1e-60; x < 1e60; x *= 1.00001) {
    acc += exp(x) * 1e-60;
  }
  return acc;
}

export function exp(x: f64): f64 { // see: musl/src/math/exp.c and SUN COPYRIGHT NOTICE above
    const
      ln2hi     = reinterpret<f64>(0x3FE62E42FEE00000), //  6.93147180369123816490e-01
      ln2lo     = reinterpret<f64>(0x3DEA39EF35793C76), //  1.90821492927058770002e-10
      invln2    = reinterpret<f64>(0x3FF71547652B82FE), //  1.44269504088896338700e+00
      P1        = reinterpret<f64>(0x3FC555555555553E), //  1.66666666666666019037e-01
      P2        = reinterpret<f64>(0xBF66C16C16BEBD93), // -2.77777777770155933842e-03
      P3        = reinterpret<f64>(0x3F11566AAF25DE2C), //  6.61375632143793436117e-05
      P4        = reinterpret<f64>(0xBEBBBD41C5D26BF1), // -1.65339022054652515390e-06
      P5        = reinterpret<f64>(0x3E66376972BEA4D0), //  4.13813679705723846039e-08
      overflow  = reinterpret<f64>(0x40862E42FEFA39EF), //  709.782712893383973096
      underflow = reinterpret<f64>(0xC0874910D52D3051), // -745.13321910194110842
      Ox1p1023  = reinterpret<f64>(0x7FE0000000000000);
    var hx = <u32>(reinterpret<u64>(x) >> 32);
    var sign_ = <i32>(hx >> 31);
    hx &= 0x7FFFFFFF;
    if (hx >= 0x4086232B) {
      if (isNaN(x)) return x;
      if (x > overflow) {
        x *= Ox1p1023;
        return x;
      }
      if (x < underflow) return 0;
    }
    var hi: f64, lo: f64 = 0;
    var k = 0;
    if (hx > 0x3FD62E42) {
      if (hx >= 0x3FF0A2B2) {
        k = <i32>(invln2 * x + copysign<f64>(0.5, x));
      } else {
        k = 1 - (sign_ << 1);
      }
      hi = x - k * ln2hi;
      lo = k * ln2lo;
      x = hi - lo;
    } else if (hx > 0x3E300000) {
      hi = x;
    } else return 1.0 + x;
    var xx = x * x;
    // var c = x - xx * (P1 + xx * (P2 + xx * (P3 + xx * (P4 + xx * P5))));
    var xx2 = xx * xx;
    var c = x - (xx * P1 + xx2 * ((P2 + xx * P3) + xx2 * (P4 + xx * P5)));
    var y = 1.0 + (x * c / (2 - c) - lo + hi);
    if (k == 0) return y;
    return Math.scalbn(y, k);
  }
