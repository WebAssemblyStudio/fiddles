
import { u256 } from "./u256";

export class u128 {

  static zero: u128 = new u128()
  static one:  u128 = new u128(1)
  static min:  u128 = u128.zero
  static max:  u128 = new u128(<u64>-1, <u64>-1)

  @inline
  static fromI64(value: i64): u128 {
    // return new u128(<u64>value, <u64>(-(<i32>(value < 0)))); // value < 0 ? -1 : 0
    return new u128(<u64>value, -(<u64>(value < 0)));
  }

  @inline
  static fromU64(value: u64): u128 {
    return new u128(value);
  }

  @inline
  static fromI32(value: i32): u128 {
    return new u128(<u64>value, -(<u64>(value < 0))); // value < 0 ? -1 : 0
  }

  @inline
  static fromU32(value: u32): u128 {
    return new u128(<u64>value);
  }

  @inline
  static fromU64Values(lo: u64, hi: u64): u128 {
    return new u128(lo, hi);
  }

  @inline
  static fromU32Values(lo1: u32, lo2: u32, hi1: u32, hi2: u32): u128 {
    return new u128(
      (<u64>lo1) | ((<u64>lo2) << 32),
      (<u64>hi1) | ((<u64>hi2) << 32),
    );
  }

  // TODO need improvement
  // max safe int for f64 actually 52-bits
  @inline
  static fromF32(value: f32): u128 {
    return new u128(<u64>value);
  }

  // TODO need improvement
  // max safe uint for f64 actually 52-bits
  @inline
  static fromF64(value: f64): u128 {
    return new u128(<u64>value);
  }

  // TODO
  // static fromString(str: string): u128

  constructor(
    public lo: u64 = 0,
    public hi: u64 = 0,
  ) {}

  @inline
  copyFrom(other: u128): this {
    this.lo = other.lo;
    this.hi = other.hi;
    return this;
  }

  @inline
  copyFromU64(value: u64): this {
    this.lo = value;
    this.hi = 0;
    return this;
  }

  @inline
  copyFromU32(value: u32): this {
    this.lo = value;
    this.hi = 0;
    return this;
  }

  /*
  @operator('~')
  static __not(value: u128): u128 {
    return new u128(~value.hi, ~value.lo);
  }

  @operator.prefix('-')
  static __neg(value: u128): u128 {
    var lo = ~this.lo, hi = ~this.hi;
    var cy = ((lo & 1) + (lo >> 1)) >> 63;
    return new u128(lo + 1, hi + cy);
  }
  */

  @inline
  not(): u128 {
    return new u128(~this.hi, ~this.lo);
  }

  @inline
  neg(): u128 {
	  var lo = ~this.lo, hi = ~this.hi;
    var cy = ((lo & 1) + (lo >> 1)) >> 63;
    return new u128(lo + 1, hi + cy);
  }

  @inline @operator('|')
  static __or(a: u128, b: u128): u128 {
    return new u128(a.lo | b.lo, a.hi | b.hi);
  }

  @inline @operator('^')
  static __xor(a: u128, b: u128): u128 {
    return new u128(a.lo ^ b.lo, a.hi ^ b.hi);
  }

  @inline @operator('&')
  static __and(a: u128, b: u128): u128 {
    return new u128(a.lo & b.lo, a.hi & b.hi);
  }

  static shl(value: u128, shift: i32): u128 {
    shift &= 127;

    var mod1: u64 = ((((shift + 127) | shift) & 64) >> 6) - 1;
    var mod2: u64 = (shift >> 6) - 1;

    shift &= 63;
    var hi = (value.lo << shift) & ~mod2;
    var lo = (value.lo << shift) & mod2;
    hi |= value.hi << shift;
    hi |= (value.lo >> (64 - shift)) & mod1;
    hi &= mod2;
    return new u128(lo, hi);
  }

  static shr(value: u128, shift: i32): u128 {
    shift &= 127;

    var mod1: u64 = ((((shift + 127) | shift) & 64) >> 6) - 1;
    var mod2: u64 = (shift >> 6) - 1;

    shift &= 63;
    var lo = (value.hi >> shift) & ~mod2;
    var hi = (value.hi >> shift) & mod2;
    lo |= value.lo >> shift;
    lo |= (value.hi << (64 - shift)) & mod1;
    lo &= mod2;
    return new u128(lo, hi);
  }

  @inline @operator('+')
  static __add(a: u128, b: u128): u128 {
    var al = a.lo;
    var bl = b.lo;
    var lo = al + bl;
    var hi = a.hi + b.hi;
    var cy = (al & bl & 1) + (al >> 1) + (bl >> 1);
    return new u128(lo, hi + (cy >> 63));
  }

  @inline @operator('-')
  static __sub(a: u128, b: u128): u128 {
    var bl = b.lo;
    var lo = a.lo - bl;
    var hi = a.hi - b.hi;
    var cy = (lo & bl & 1) + (bl >> 1) + (lo >> 1);
    return new u128(lo, hi - (cy >> 63));
  }

  // mul u128 x u128 = u128
  @operator('*')
  static __mul(a: u128, b: u128): u128 {
    var u = a.lo, v = b.lo;
    var w1: u64, k: u64;

    var u1 = u & <u64>-1;
    var v1 = v & <u64>-1;
    var t  = u1 * v1;
    var w2 = t & <u64>-1;

    u  >>= 32;
    t  = u * v1 + (t >> 32);
    k  = t & <u64>-1;
    w1 = t >> 32;

    v >>= 32;
    t = u1 * v + k;

    var lo  = w2 + (t << 32);
    var hi  = u * v + w1 + (t >> 32);
        hi += a.hi * b.lo;
        hi += a.lo * b.hi;

    return new u128(lo, hi);
  }

  // wide mul: u128 x u128 = u256
  wmul(other: u128): u256 {
    return u256.zero;
  }

  @inline @operator('==')
  static __eq(a: u128, b: u128): bool {
    return a.hi == b.hi && a.lo == b.lo;
  }

  @inline @operator('!=')
  static __ne(a: u128, b: u128): bool {
    return a.hi != b.hi && a.lo != b.lo;
  }

  @inline @operator('>=')
  static __ge(a: u128, b: u128): bool {
    return a.hi >= b.hi && a.lo >= b.lo;
  }

  @inline @operator('<=')
  static __le(a: u128, b: u128): bool {
    return a.hi <= b.hi && a.lo <= b.lo;
  }

  @inline @operator('>')
  static __gt(a: u128, b: u128): bool {
    return a.hi > b.hi && a.lo > b.lo;
  }

  @inline @operator('<')
  static __ls(a: u128, b: u128): bool {
    return a.hi < b.hi && a.lo < b.lo;
  }

  @inline
  static popcnt(value: u128): i32 {
    return <i32>(popcnt(value.lo) + popcnt(value.hi));
  }

  @inline
  static clz(value: u128): i32 {
    return <i32>(value.hi ? clz(value.hi) : clz(value.lo) + 64);
  }

  @inline
  static ctz(value: u128): i32 {
    return <i32>(value.lo ? ctz(value.lo) : ctz(value.hi) + 64);
  }

  @inline
  toI64(): i64 {
	  return <i64>((this.lo & 0x7FFFFFFFFFFFFFFF) | (this.hi & 0x8000000000000000));
  }

  @inline
  toU64(): u64 {
	  return this.lo;
  }

  toF64(): f64 {
    const fshift = reinterpret<f64>(0x43F0000000000000); // 18446744073709551616.0
    var hi = this.hi, lo = this.lo;
  	if (<i64>hi >= 0) {
      return <f64>hi * fshift + <f64>lo;
    }

  	var h: i64 = ~hi;
  	var l: u64 = ~lo;

  	l += 1;
  	h += <i64>(l == 0);

  	return -(<f64>h * fshift + <f64>l);
  }

  @inline
  toF32(): f32 {
    return <f32>this.toF64();
  }

  toBytesLE(): u8[] {
    var hi = this.hi, lo = this.lo;
    var result: u8[] = [
      <u8>(lo >>  0), <u8>(lo >>  8), <u8>(lo >> 16), <u8>(lo >> 24),
      <u8>(lo >> 32), <u8>(lo >> 40), <u8>(lo >> 48), <u8>(lo >> 56),

      <u8>(hi >>  0), <u8>(hi >>  8), <u8>(hi >> 16), <u8>(hi >> 24),
      <u8>(hi >> 32), <u8>(hi >> 40), <u8>(hi >> 48), <u8>(hi >> 56),
    ];
    return result;
  }

  // TODO
  // toString(): string
}

export class u256 {
  static zero: u256 = new u256()
  static one:  u256 = new u256(1)
  static min:  u256 = u256.zero
  static max:  u256 = new u256(<u64>-1, <u64>-1, <u64>-1, <u64>-1)

  @inline
  static fromU128(value: u128): u256 {
    return new u256(value.lo, value.hi);
  }

  @inline
  static fromU64(value: u64): u256 {
    return new u256(value);
  }

  @inline
  static fromI64(value: i64): u256 {
    return new u256(value, 0, 0, <u64>(-(<i32>(value < 0))));
  }

  @inline
  static fromU128Values(lo: u128, hi: u128): u256 {
    return new u256(lo.lo, lo.hi, hi.lo, hi.hi);
  }

  @inline
  static fromU64Values(lo1: u64, lo2: u64, hi1: u64, hi2: u64): u256 {
    return new u256(lo1, lo2, hi1, hi2);
  }

  @inline
  static fromU32Values(
    l0: u32, l1: u32, l2: u32, l3: u32,
    h0: u32, h1: u32, h2: u32, h3: u32,
  ): u256 {
    return new u256(
      (<u64>l0) | ((<u64>l1) << 32),
      (<u64>l2) | ((<u64>l3) << 32),
      (<u64>h0) | ((<u64>h1) << 32),
      (<u64>h2) | ((<u64>h3) << 32),
    );
  }

  // TODO need improvement
  // max safe int for f64 actually 52-bits
  @inline
  static fromF32(value: f32): u256 {
    return new u256(<u64>value);
  }

  // TODO need improvement
  // max safe uint for f64 actually 52-bits
  @inline
  static fromF64(value: f64): u256 {
    return new u256(<u64>value);
  }

  constructor(
    public lo1: u64 = 0,
    public lo2: u64 = 0,
    public hi1: u64 = 0,
    public hi2: u64 = 0,
  ) {}

  @inline
  copyFrom(other: u256): this {
    this.lo1 = other.lo1;
    this.lo2 = other.lo2;
    this.hi1 = other.hi1;
    this.hi2 = other.hi2;
    return this;
  }

  @inline
  copyFromU128(value: u128): this {
    this.lo1 = value.lo;
    this.lo2 = value.hi;
    this.hi1 = 0;
    this.hi2 = 0;
    return this;
  }

  @inline
  copyFromI64(value: i64): this {
    this.lo1 = value;
    this.lo2 = 0;
    this.hi1 = 0;
    this.hi2 = <u64>(-(<i32>(value < 0)));
    return this;
  }

  @inline
  copyFromU64(value: u64): this {
    this.lo1 = value;
    this.lo2 = 0;
    this.hi1 = 0;
    this.hi2 = 0;
    return this;
  }

  @inline
  copyFromI32(value: i32): this {
    this.lo1 = value;
    this.lo2 = 0;
    this.hi1 = 0;
    this.hi2 = <u64>(-(<i32>(value < 0)));
    return this;
  }

  @inline
  copyFromU32(value: u32): this {
    this.lo1 = value;
    this.lo2 = 0;
    this.hi1 = 0;
    this.hi2 = 0;
    return this;
  }

  // TODO
  // toString(): string
}
