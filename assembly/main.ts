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
    // s -= 2;
    let res = <T>0;
    while (s >= 0) {
      res <<= 1;
      let m = res + 1;
      if (m * m <= x >> <T>s) {
        res = m;
      }
      s -= 2;
    }
    return res;
  }
  throw new TypeError("Unexpected generic type");
}

log(sqrt(i32.MAX_VALUE));
// 2 147 488 281
// 2 147 483 647
