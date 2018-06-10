import "allocator/arena";

declare function log(lo: u64, hi: u64): void;

class u128 {
  constructor(
    public lo: u64 = 0,
    public hi: u64 = 0,
  ) {}

  @operator('*')
  static mul(a: u128, b: u128): u128 {
    var al = a.lo,
        bl = b.lo;
    var ah = a.hi,
        bh = b.hi;
    var u  = al,
        v  = bl;

    var w: u64, k: u64;

    var u1 = u & 0xFFFFFFFF;
    var v1 = v & 0xFFFFFFFF;
    var t  = u1 * v1;
    var w1 = t & 0xFFFFFFFF;

    u = u >> 32;
    t = u * v1 + (t >> 32);
    k = t & 0xFFFFFFFF;
    w = t >> 32;
    v = v >> 32;
    t = u1 * v + k;

    var lo  = w1 + (t << 32);
    var hi  = u  * v + w;
        hi += ah * bl;
        hi += al * bh;
        hi += t >> 32;

    return new u128(lo, hi);
  }
}

let a = new u128(2);
let b = new u128(100);
let c = a * b;

log(c.lo, c.hi);