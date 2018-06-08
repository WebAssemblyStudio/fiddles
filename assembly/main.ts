
import "allocator/arena";

class u128 {
  constructor(
    public lo: u64 = 0,
    public hi: u64 = 0
  ) {}

  @inline
  static add(a: u128, b: u128): u128 {
    var al = a.lo;
    var bl = b.lo;
    var lo = al   + bl;
    var hi = a.hi + b.hi;
    var cy = (al & bl & 1) + (al >> 1) + (bl >> 1);
    return new u128(lo, hi + (cy >> 63));
  }

  @inline
  static add2(a: u128, b: u128): u128 {
    var al = a.lo;
    var bl = b.lo;
    var lo = al   + bl;
    var hi = a.hi + b.hi;
    hi += <u64>(lo < b.lo);
    return new u128(lo, hi);
  }
}

export function main(): u128 {
  var a = new u128(3);
  var b = new u128(100, 1);
  return u128.add2(a, b);
}