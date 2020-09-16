

export function isqrt(n: u64): u64 {
  if (n < 2) return n;
  let xk = n >> (64 - clz(n) >> 1);

  xk = (xk + n / xk) >> 1;
  xk = (xk + n / xk) >> 1;
  let xkn = (xk + n / xk) >> 1;

  let _max = max(xk, xkn);
  let _min = min(xk, xkn);

  while (_max - _min > 1) {
    xk = xkn + ((n / xkn) >> 1);
    xk += ((n / xk) >> 1);
    xk += ((n / xk) >> 1);
    xkn = xk + ((n / xk) >> 1);

    _max = max(xk, xkn);
    _min = min(xk, xkn);
  }
  return _min;
}

export function isqrt2(n: u64): u64 {
  if (n < 2) return n;

  let res: u32 = 0;
  let add: u32 = 0x80000000;
  let tmp: u64;
  for (let i = 0; i < 32; ++i) {
    tmp = res | add;
    let sqr = tmp * tmp;
    if (n >= sqr) {
      res = u32(tmp);
    }
    add >>= 1;
  }
  return u64(res);
}

export function isqrt3(n: u64): u64 {
  if (n < 2) return n;
  let root: u64 = 0;
  let rmdr: u64 = 0;
  let bits = i64(64 - clz(n));
  for (let s = bits - 1; s >= 0; s -= 2) {
    bits = (n >> s) & 3;
    rmdr = (rmdr << 2) | bits;
    let cand = (root << 2) | 1;
    let bit_next = u64(rmdr >= cand);
    root = (root << 1) | bit_next;
    rmdr -= cand * bit_next;
  }
  return root;
}

export function isqrt4(n: u64): u64 {
  if (n < 2) return n;
  let res: u64 = 0, rem = n
  let pos: u64 = 1 << 63 - clz(n)
  while (pos) {
    n = res + pos
    if (rem >= n) {
      rem -= n
      res = pos + n
    }
    res >>>= 1
    pos >>>= 2
  }
  return res
}

export function isqrt_f(x: u64): u64 {
  return Math.sqrt(f64(x)) as u64;
}

export function sqrt(x: f64): f64 {
  return Math.sqrt(x);
}
