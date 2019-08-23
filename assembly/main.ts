export function isqrt32_1(x: u32): u32 {
  if (x < 2) return x;
  var s = 2;
  var xs = x >> 2;
  while (xs && xs != x) {
    s += 2;
    xs = x >> s;
  }
  s -= 2;
  var ux = x;
  var res: u32 = 0;
  while (s >= 0) {
    res <<= 1;
    let m = res + 1;
    if (m * m <= ux >> s) {
      res = m;
    }
    s -= 2;
  }
  return res;
}

export function isqrt32_2(value: u32): u32 {
  if (!value) return 0;
  let shift = (32 - clz(value)) >>> 1;
  let xn = <u32>1 << shift;
  xn = (xn + (value >> shift)) >>> 1;
  xn = (xn + value / xn) >>> 1;
  xn = (xn + value / xn) >>> 1;
  return xn - i32(xn * xn > value);
}

export function isqrt32_3(value: u32): u32 {
  return <u32>Math.sqrt(value);
}


