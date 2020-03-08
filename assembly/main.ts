declare namespace console {
  function logf(value: f64): void;
}

export function upow(base: u64, exponent: i32): u64 {
  if (exponent < 0) return 0;
  switch (exponent) {
    case 0: return 1;
    case 1: return base;
    case 2: return base * base;
  }

  var result: u64 = 1;
  var bs = 32 - clz(exponent);
  // if (bs > 6) return 0;

  // 64 = 2 ^ 6, so need only six cases
  switch (bs) {
    default:
    case 6: {
      if (exponent & 1) result *= base;
      exponent >>= 1;
      base *= base;
    }
    case 5: {
      if (exponent & 1) result *= base;
      exponent >>= 1;
      base *= base;
    }
    case 4: {
      if (exponent & 1) result *= base;
      exponent >>= 1;
      base *= base;
    }
    case 3: {
      if (exponent & 1) result *= base;
      exponent >>= 1;
      base *= base;
    }
    case 2: {
      if (exponent & 1) result *= base;
      exponent >>= 1;
      base *= base;
    }
    case 1: {
      if (exponent & 1) result *= base;
    }
  }

  return result;
}

const ITERS: i32 = 10000000;

export function test1(): f64 {
  let r: u64 = 0;
  for (let i = 0; i < ITERS; ++i) {
    r += upow((i & 15), (i & 7));
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