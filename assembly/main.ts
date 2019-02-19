declare function log(x: f64): void;

function sqrt<T>(x: T): T {
  if (isInteger<T>()) {
    if (isSigned<T>()) {
      if (x < 0) throw new RangeError("Math.sqrt received negative argument");
    }
    if (!x) return <T>0;
    let s = 2;
    let xs = x >> 2;
    while (xs && xs != x) {
      s += 2;
      xs = x >> <T>s;
    }
    s -= 2;
    let res = <T>0;
    while (s >= 0) {
      res <<= 1;
      let m = res + 1;
      if (m * m <= (x >> <T>s)) {
        res = m;
      }
      s -= 2;
    }
    return res;
  }
  throw new TypeError("Unexpected generic type");
}

log(sqrt<u32>(i16.MAX_VALUE)); // ok (181)
log(sqrt<i32>(i16.MAX_VALUE)); // ok (181)
log(sqrt<u16>(i16.MAX_VALUE)); // ok (181)
log(sqrt<i16>(i16.MAX_VALUE)); // ok (181)

log(sqrt<u32>(i32.MAX_VALUE)); // ok (46340)
log(sqrt<i32>(i32.MAX_VALUE)); // fail (46341)
