export function test(): f64 {
  var acc = 0.0;
  for (let i: f64 = 0; i < 10000000.0; ++i) {
    acc += (i * 10000.0) % acc;
  }
  return acc;
}

function rem(x: f64, y: f64): f64 { // see: musl/src/math/remquo.c
  var ux = reinterpret<u64>(x);
  var uy = reinterpret<u64>(y);
  var ex = <i64>(ux >> 52 & 0x7FF);
  var ey = <i64>(uy >> 52 & 0x7FF);
  var sx = <i32>(ux >> 63);
  var sy = <i32>(uy >> 63);
  if (uy << 1 == 0 || ex == 0x7FF || isNaN(y)) return (x * y) / (x * y);
  if (ux << 1 == 0) return x;
  var uxi = ux;
  if (!ex) {
    ex -= clz<i64>(uxi << 12);
    uxi <<= -ex + 1;
  } else {
    uxi &= <u64>-1 >> 12;
    uxi |= 1 << 52;
  }
  if (!ey) {
    ey -= clz<i64>(uy << 12);
    uy <<= -ey + 1;
  } else {
    uy &= <u64>-1 >> 12;
    uy |= 1 << 52;
  }
  var q: u32 = 0;
  do {
    if (ex < ey) {
      if (ex + 1 == ey) break; // goto end
      return x;
    }
    let i: u64;
    for (; ex > ey; ex--) {
      i = uxi - uy;
      if (i >> 63 == 0) {
        uxi = i;
        ++q;
      }
      uxi <<= 1;
      q <<= 1;
    }
    i = uxi - uy;
    if (i >> 63 == 0) {
      uxi = i;
      ++q;
    }
    if (uxi == 0) ex = -60;
    else {
      let shift = clz<i64>(uxi << 11);
      ex -= shift;
      uxi <<= shift;
    }
    break;
  } while (false);
// end:
  if (ex > 0) {
    uxi -= 1 << 52;
    uxi |= ex << 52;
  } else {
    uxi >>= -ex + 1;
  }
  x = reinterpret<f64>(uxi);
  if (sy) y = -y;
  var x2 = x + x;
  if (ex == ey || (ex + 1 == ey && (x2 > y || (x2 == y && <bool>(q & 1))))) {
    x -= y;
    // ++q;
  }
  return sx ? -x : x;
}

export function test2(): f64 {
  var acc = 0.0;
  for (let i: f64 = 0; i < 10000000.0; ++i) {
    acc += rem(i * 10000.0, acc);
  }
  return acc;
}
