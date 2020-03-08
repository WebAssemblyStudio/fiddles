declare namespace console {
  function logf(value: f64): void;
}
export function ipow64(x: i64, e: i64): i64 {
  var out: i64 = 1;
  if (ASC_SHRINK_LEVEL < 1) {
    if (e < 64) {
      if (e <= 0) return i64(e == 0) | i64(x == 1);
      if (e == 1) return x;
      if (e == 2) return x * x;

      let log = 64 - <i32>clz(e);
      // 64 = 2 ^ 6, so need only six cases.
      // But some extra cases needs for properly overflowing
      switch (log) {
        case 6: {
          if (e & 1) out *= x;
          e >>>= 1;
          x *= x;
        }
        case 5: {
          if (e & 1) out *= x;
          e >>>= 1;
          x *= x;
        }
        case 4: {
          if (e & 1) out *= x;
          e >>>= 1;
          x *= x;
        }
        case 3: {
          if (e & 1) out *= x;
          e >>>= 1;
          x *= x;
        }
        case 2: {
          if (e & 1) out *= x;
          e >>>= 1;
          x *= x;
        }
        case 1: {
          if (e & 1) out *= x;
        }
      }
      return out;
    }
  }
  while (e) {
    if (e & 1) out *= x;
    e >>>= 1;
    x *= x;
  }
  return out;
}

const ITERS: i32 = 10000000;

export function test1(): f64 {
  let r: u64 = 0;
  for (let i = 0; i < ITERS; ++i) {
    r += ipow64((i & 15), (i & 7));
  }
  return <f64>r;
}


export function test2(): f64 {
  let r: u64 = 0;
  for (let i = 0; i < ITERS; ++i) {
    r += <u64>Math.pow(<f64>(i & 15), (i & 7));
  }
  return <f64>r;
}