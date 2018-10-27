export function test(): f64 {
  var acc = 2.3;
  for (let i: f64 = 0; i < 10000000.0; ++i) {
    acc += (i * 10000.0) % acc;
  }
  return acc;
}

function mod(x: f64, y: f64): f64 { // see: musl/src/math/remquo.c
  var ux = reinterpret<u64>(x);
  var uy = reinterpret<u64>(y);
  var ex = <i64>(ux >> 52 & 0x7FF);
  var ey = <i64>(uy >> 52 & 0x7FF);
  var sx = ux >> 63;
  var uy1 = uy << 1;
  if (uy1 == 0 || ex == 0x7FF || isNaN<f64>(y)) return (x * y) / (x * y);
  var ux1 = ux << 1;
  if (ux1 <= uy1) {
    if (ux1 == uy1) return 0 * x;
    return x;
  }
  if (!ex) {
    ex -= clz<i64>(ux << 12);
    ux <<= -ex + 1;
  } else {
    ux &= <u64>-1 >> 12;
    ux |= 1 << 52;
  }
  if (!ey) {
    ey -= clz<i64>(uy << 12);
    uy <<= -ey + 1;
  } else {
    uy &= <u64>-1 >> 12;
    uy |= 1 << 52;
  }
  var i: i64;
  while (ex > ey) {
    i = ux - uy;
    if (i >= 0) {
      if (!i) return 0 * x;
      ux = <u64>i;
    }
    ux <<= 1;
    --ex;
  }
  i = ux - uy;
  if (i >= 0) {
    if (!i) return 0 * x;
    ux = <u64>i;
  }
  // for (; !(ux >> 52); ux <<= 1) --ex;
  var shift = clz<i64>(ux << 11);
  ex -= shift;
  ux <<= shift;
  if (ex > 0) {
    ux -= 1 << 52;
    ux |= ex << 52;
  } else {
    ux >>= -ex + 1;
  }
  ux |= sx << 63;
  return reinterpret<f64>(ux);
}

export function test2(): f64 {
  var acc = 2.3;
  for (let i: f64 = 0; i < 10000000.0; ++i) {
    acc += mod(i * 10000.0, acc);
  }
  return acc;
}
