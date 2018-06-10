import "allocator/arena";

declare function log(v: f64): void;

class u128 {
  static readonly Zero: u128 = new u128()
  static readonly One:  u128 = new u128(1)
  static readonly Min:  u128 = u128.Zero
  static readonly Max:  u128 = new u128(u64.MAX_VALUE, u64.MAX_VALUE)

  constructor(
    public lo: u64 = 0,
    public hi: u64 = 0,
  ) {}

  @inline
  static fromU128(value: u128): u128 {
    return new u128(value.lo, value.hi);
  }

  @inline @operator('<<')
  static shl(value: u128, shift: i32): u128 {
    shift &= 127;

    // need for preventing redundant i32 -> u64 extends
    var shift64: u64 = shift;

    var mod1: u64 = ((((shift64 + 127) | shift64) & 64) >> 6) - 1;
    var mod2: u64 = (shift64 >> 6) - 1;

    shift64 &= 63;

    var vl = value.lo;
    var lo = vl << shift64;
    var hi = (vl << shift64) & ~mod2;

    hi |= ((value.hi << shift64) | ((vl >> (64 - shift64)) & mod1)) & mod2;

    return new u128(lo & mod2, hi);

    // return new u128(value.lo << shift64, (value.lo >> (64 - shift64)) | (value.hi << shift64));
  }

    // mul: u128 x u128 = u128
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

  @operator('**')
  static pow(base: u128, exponent: i32): u128 {

    // any negative exponent produce zero
    if (exponent < 0)
      return u128.Zero;

    switch (exponent) {
      case 0: return u128.One;
      case 1: return base.clone();
      default: break;
    }

    if (base.hi == 0) {
      // "1 ^ exponent" always return "1"
      if (base.lo == 1)
        return u128.One;

      // if base is power of two do "1 << log2(base) * exp"
      if (!(base.lo & (base.lo - 1))) {
               log(-1.0);
        return u128.One << <i32>(128 - clz(base.lo - 1) - 64) * exponent;
      }
    } else if (base.lo == 0) {
      // if base is power of two do "1 << log2(base) * exp"
      if (!(base.hi & (base.hi - 1)))
        return u128.One << <i32>(128 - clz(base.hi - 1)) * exponent;
    }

    switch (exponent) {
      case 2: return u128.sqr(base);
      case 3: return base * u128.sqr(base);
      case 4: return u128.sqr(base).sqr();
      default: break;
    }

    /*
    var result = base.clone();
    for (let i = 31 - Math.clz32(exponent) - 1; i >= 0; --i) {
      result = u128.sqr(r);
      if ((exponent >>> i) & 1)
        result *= base;
    }
    */

    var result = u128.One;
    var tmp    = base.clone();
    var bs     = 32 - clz(exponent);

    log(<f64>bs);

    // 128 = 2 ^ 7, so need only seven cases
    switch (bs) {
      case 8: // FIXME really need eight step? Will decide during tests
        if (exponent & 1) result *= tmp;
        exponent >>= 1;
        tmp.sqr();
      case 7:
        if (exponent & 1) result *= tmp;
        exponent >>= 1;
        tmp.sqr();
      case 6:
        if (exponent & 1) result *= tmp;
        exponent >>= 1;
        tmp.sqr();
      case 5:
        if (exponent & 1) result *= tmp;
        exponent >>= 1;
        tmp.sqr();
      case 4:
        if (exponent & 1) result *= tmp;
        exponent >>= 1;
        tmp.sqr();
      case 3:
        if (exponent & 1) result *= tmp;
        exponent >>= 1;
        tmp.sqr();
      case 2:
        if (exponent & 1) result *= tmp;
        exponent >>= 1;
        tmp.sqr();
      case 1:
        if (exponent & 1) result *= tmp;

      default: break;
    }

    return result;
  }

  static sqr(value: u128): u128 {
    return u128.fromU128(value).sqr();
  }

  sqr(): this {
    var u = this.lo,
        v = this.hi;

    var u1 = u & 0xFFFFFFFF;
    var t  = u1 * u1;
    var w  = t & 0xFFFFFFFF;
    var k  = t >> 32;

    u >>= 32;
    var m = u * u1;
    t = m + k;
    var w1 = t >> 32;

    t = m + (t & 0xFFFFFFFF);

    var lo = (t << 32) + w;
    var hi   = u * u + w1 + (t >> 32);
        hi  += v * u;
        hi <<= 1;

    this.lo = lo;
    this.hi = hi;

    return this;
  }

  @inline
  clone(): u128 {
    return new u128(this.lo, this.hi);
  }

  toF64(): f64 {
    var lo = this.lo, hi = this.hi;
    const shift = reinterpret<f64>(0x43F0000000000000); // 2 ^ 64
    if (hi >= 0)
      return <f64>hi * shift + <f64>lo;

    var rh: i64 = ~hi;
    var rl: u64 = ~lo;

    var cy = ((rl & 1) + (rl >> 1)) >> 63;
    rl += 1;
    rh += cy;

    return -(<f64>rh * shift + <f64>rl);
  }
}

var a = new u128(3);
var r = a ** 80;

log(r.toF64());

log(<f64>r.lo);
log(<f64>((r.hi >> 32) & 0xFFFFFFFF));
