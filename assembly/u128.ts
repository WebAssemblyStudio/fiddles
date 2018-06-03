
import { u256 } from './u256';

const HEX_CHARS = '0123456789abcdef';

export class u128 {

  // TODO need decide
  // still possible mutate by unary increment/decremrnt ops
  // May be better use get accsessors?
  static readonly Zero: u128 = new u128()
  static readonly One:  u128 = new u128(1)
  static readonly Min:  u128 = u128.Zero
  static readonly Max:  u128 = new u128(u64.MAX_VALUE, u64.MAX_VALUE)

  @inline
  static fromU256(value: u256): u128 {
    return new u128(value.lo1, value.lo2);
  }

  @inline
  static fromU128(value: u128): u128 {
    return new u128(value.lo, value.hi);
  }

  @inline
  static fromI64(value: i64): u128 {
    return new u128(<u64>value, -(<u64>(value < 0)));
  }

  @inline
  static fromU64(value: u64): u128 {
    return new u128(value);
  }

  @inline
  static fromI32(value: i32): u128 {
    return new u128(<u64>value, -(<u64>(value < 0)));
  }

  @inline
  static fromU32(value: u32): u128 {
    return new u128(<u64>value);
  }

  @inline
  static from64Bits(lo: u64, hi: u64): u128 {
    return new u128(lo, hi);
  }

  @inline
  static from32Bits(lo1: u32, lo2: u32, hi1: u32, hi2: u32): u128 {
    return new u128(
      (<u64>lo1) | ((<u64>lo2) << 32),
      (<u64>hi1) | ((<u64>hi2) << 32),
    );
  }

  @inline
  static fromBytes(array: u8[], le: bool = true): u128 {
    return le ? u128.fromBytesLE(array) : u128.fromBytesBE(array);
  }

  static fromBytesLE(array: u8[]): u128 {
    assert(array && array.length == 16);

    var lo: u64 = 0, hi: u64 = 0;
    for (let i = 0; i <  8; ++i) lo |= unchecked(array[i]) << (i << 3);
    for (let i = 8; i < 16; ++i) hi |= unchecked(array[i]) << (i << 3);

    return new u128(lo, hi);
  }

  static fromBytesBE(array: u8[]): u128 {
    assert(array && array.length == 16);

    var lo: u64 = 0, hi: u64 = 0;
    for (let i = 0; i <  8; ++i) hi |= unchecked(array[i]) << ((7  - i) << 3);
    for (let i = 8; i < 16; ++i) lo |= unchecked(array[i]) << ((15 - i) << 3);

    return new u128(lo, hi);
  }

  // TODO need improvement
  // max safe uint for f64 actually 52-bits
  @inline
  static fromF64(value: f64): u128 {
    return new u128(<u64>value);
  }

  // TODO need improvement
  // max safe int for f32 actually 23-bits
  @inline
  static fromF32(value: f32): u128 {
    return new u128(<u64>value);
  }

  // TODO
  // static fromString(str: string): u128

  constructor(
    public lo: u64 = 0,
    public hi: u64 = 0,
  ) {}

  @inline
  set(value: u128): this {
    this.lo = value.lo;
    this.hi = value.hi;
    return this;
  }

  @inline
  setI64(value: i64): this {
    this.lo = value;
    this.hi = -(<u64>(value < 0));
    return this;
  }

  @inline
  setU64(value: u64): this {
    this.lo = value;
    this.hi = 0;
    return this;
  }

  @inline
  setI32(value: i32): this {
    this.lo = value;
    this.hi = -(<u64>(value < 0));
    return this;
  }

  @inline
  setU32(value: u32): this {
    this.lo = value;
    this.hi = 0;
    return this;
  }

  @inline // @operator('~')
  not(): u128 {
    return new u128(~this.hi, ~this.lo);
  }

  @inline // @operator.prefix('-')
  neg(): u128 {
	  var lo = ~this.lo, hi = ~this.hi;
    var cy = ((lo & 1) + (lo >> 1)) >> 63;
    return new u128(-lo, hi + cy);
  }

  @inline
  inc(): this {
    var tmp  = this.lo + 1;
    this.hi += ((this.lo ^ tmp) & this.lo) >> 63;
    this.lo  = tmp;
    return this;
  }

  @inline
  dec(): this {
    var tmp  = this.lo - 1;
    this.hi -= ((this.lo ^ tmp) & tmp) >> 63;
    this.lo  = tmp;
    return this;
  }

  @inline // @operator.prefix('!')
  static isEmpty(value: u128): bool {
    return !value || !(value.lo | value.hi);
  }

  @inline @operator('|')
  static or(a: u128, b: u128): u128 {
    return new u128(a.lo | b.lo, a.hi | b.hi);
  }

  @inline @operator('^')
  static xor(a: u128, b: u128): u128 {
    return new u128(a.lo ^ b.lo, a.hi ^ b.hi);
  }

  @inline @operator('&')
  static and(a: u128, b: u128): u128 {
    return new u128(a.lo & b.lo, a.hi & b.hi);
  }

  @inline // @operator('<<')
  static shl(value: u128, shift: i32): u128 {
    shift &= 127;

    var mod1: u64 = ((((shift + 127) | shift) & 64) >> 6) - 1;
    var mod2: u64 = (shift >> 6) - 1;

    shift &= 63;

    // need for prevent redundant i32 >> u64 extends
    var shift64: u64 = shift;

    var lo = value.lo << shift64;
    var hi = lo & ~mod2;

    hi |=  value.hi << shift64;
    hi |= (value.lo >> (64 - shift64)) & mod1;

    return new u128(lo & mod2, hi & mod2);
  }

  /*
  @inline @operator('>>')
  static sar(value: u128, shift: i32): u128 {
    return u128.shr(value, shift);
  }
  */

  @inline // @operator('>>>')
  static shr(value: u128, shift: i32): u128 {
    shift &= 127;

    var mod1: u64 = ((((shift + 127) | shift) & 64) >> 6) - 1;
    var mod2: u64 = (shift >> 6) - 1;

    shift &= 63;

    // need for prevent redundant i32 >> u64 extends
    var shift64: u64 = shift;

    var hi = value.hi >> shift64;
    var lo = hi & ~mod2;

    lo |=  value.lo >> shift64;
    lo |= (value.hi << (64 - shift64)) & mod1;

    return new u128(lo & mod2, hi & mod2);
  }

  @inline @operator('+')
  static add(a: u128, b: u128): u128 {
    var al = a.lo;
    var bl = b.lo;
    var lo = al   + bl;
    var hi = a.hi + b.hi;
    var cy = (al & bl & 1) + (al >> 1) + (bl >> 1);
    return new u128(lo, hi + (cy >> 63));
  }

  @inline @operator('-')
  static sub(a: u128, b: u128): u128 {
    var bl = b.lo;
    var lo = a.lo - bl;
    var hi = a.hi - b.hi;
    var cy = (lo & bl & 1) + (bl >> 1) + (lo >> 1);
    return new u128(lo, hi - (cy >> 63));
  }

  // mul: u128 x u128 = u128
  @operator('*')
  static mul(a: u128, b: u128): u128 {
    var u = a.lo, v = b.lo;
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
    var hi  = u * v + w;
        hi += a.hi * b.lo;
        hi += a.lo * b.hi;
        hi += t >> 32;

    return new u128(lo, hi);
  }

  // wide mul: u128 * u128 = u256
  static mul256(a: u128, b: u128): u256 {
    // TODO
    unreachable();
    return u256.Zero;
  }

  // TODO @operator('/')
  // TODO @operator('%')

  @inline @operator('==')
  static eq(a: u128, b: u128): bool {
    return a.hi == b.hi && a.lo == b.lo;
  }

  @inline @operator('!=')
  static ne(a: u128, b: u128): bool {
    return !u128.eq(a, b);
  }

  @inline @operator('<')
  static lt(a: u128, b: u128): bool {
    var ah = a.hi, bh = b.hi;
    return ah == bh ? a.lo < b.lo : ah < bh;
  }

  @inline @operator('>')
  static gt(a: u128, b: u128): bool {
    var ah = a.hi, bh = b.hi;
    return ah == bh ? a.lo > b.lo : ah > bh;
  }

  @inline @operator('<=')
  static le(a: u128, b: u128): bool {
    return !u128.gt(a, b);
  }

  @inline @operator('>=')
  static ge(a: u128, b: u128): bool {
    return !u128.lt(a, b);
  }

  @inline
  static cmp(a: u128, b: u128): i32 {
    var diff: i64 = a.hi - b.hi;
    return <i32>(diff != 0 ? diff : a.lo - b.lo);
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

  // Overflow / undeflow safed operations
  // TODO move this methods to `safe` namespace as overriden operators when polymorpthism landed

  // tmp approach
  @inline
  safeInc(): this {
    assert(this.hi != <u64>-1);
    return this.inc();
  }

  // tmp approach
  @inline
  safeDec(): this {
    assert(this.lo != 0);
    return this.dec();
  }

  // tmp approach
  @inline
  safeAdd(other: u128): u128 {
    // overflow guard
    assert(clz(this.hi) | clz(other.hi));
    return u128.add(this, other);
  }

  // tmp approach
  @inline
  safeSub(other: u128): u128 {
    // underflow guard
    assert(this >= other);
    return u128.sub(this, other);
  }

  // tmp approach
  @inline
  safeMul(other: u128): u128 {
    // count leading zero bits for operands
    var azn = u128.clz(this);
    var bzn = u128.clz(other);

    // if a == 0 || b == 0
    if (azn == 128 || azn == 128)
      return u128.Zero;

    // if a == 1 || b == 1
    if (azn == 127) return other.clone();
    if (bzn == 127) return this.clone();

    // overflow guard
    assert(azn + bzn >= 128);

    return u128.mul(this, other);
  }

  // tmp approach
  @inline
  safeDiv(other: u128): u128 {
    assert(other != 0);
    // TODO need implement
    unreachable();
    return u128.Zero;
  }

  // tmp approach
  @inline
  safeRem(other: u128): u128 {
    assert(other != 0);
    // TODO need implement
    unreachable();
    return u128.Zero;
  }

  /**
  * Convert to 256-bit unsigned integer
  */
  @inline
  toU256(): u256 {
	  return new u256(this.lo, this.hi);
  }

  /**
  * Convert to 64-bit signed integer
  */
  @inline
  toI64(): i64 {
	  return <i64>(
      (this.lo & 0x7FFFFFFFFFFFFFFF) |
      (this.hi & 0x8000000000000000)
    );
  }

  /**
  * Convert to 64-bit unsigned integer
  */
  @inline
  toU64(): u64 {
	  return this.lo;
  }

  /**
  * Convert to 32-bit signed integer
  */
  @inline
  toI32(): i32 {
	  return <i32>this.toI64();
  }

  /**
  * Convert to 32-bit unsigned integer
  */
  @inline
  toU32(): u32 {
	  return <u32>this.lo;
  }

  /**
  * Convert to 64-bit float number
  */
  toF64(): f64 {
    const fshift = reinterpret<f64>(0x43F0000000000000); // 18446744073709551616.0
    var hi = this.hi, lo = this.lo;
  	if (hi >= 0) {
      return <f64>hi * fshift + <f64>lo;
    }

  	var rh: i64 = ~hi;
  	var rl: u64 = ~lo;

  	rl += 1;
  	rh += <i64>(rl == 0);

  	return -(<f64>rh * fshift + <f64>rl);
  }

  /**
  * Convert to 32-bit float number
  */
  @inline
  toF32(): f32 {
    return <f32>this.toF64();
  }

  /**
  * Convert to byte array
  *
  * @param le Is little endian? Default: true
  */
  @inline
  toBytes(le: bool = true): u8[] {
    return le ? this.toBytesLE() : this.toBytesBE();
  }

  /**
  * Convert to little endian byte array
  */
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

  /**
  * Convert to big endian byte array
  */
  toBytesBE(): u8[] {
    var hi = this.hi, lo = this.lo;

    var result: u8[] = [
      <u8>(hi >> 56), <u8>(hi >> 48), <u8>(hi >> 40), <u8>(hi >> 32),
      <u8>(hi >> 24), <u8>(hi >> 16), <u8>(hi >>  8), <u8>(hi >>  0),

      <u8>(lo >> 56), <u8>(lo >> 48), <u8>(lo >> 40), <u8>(lo >> 32),
      <u8>(lo >> 24), <u8>(lo >> 16), <u8>(lo >>  8), <u8>(lo >>  0),
    ];

    return result;
  }

  /**
  * Clone/copy
  */
  @inline
  clone(): u128 {
    return new u128(this.lo, this.hi);
  }

  // TODO compleate and improve this
  toString(radix: i32 = 16): string {
    if (this.lo == 0 && this.hi == 0)
      return '0';

    var result = '';
    var it = this.clone();
    if (radix == 16) {
      let shift: i32 = 124 - (u128.clz(it) & ~3);
      while (shift >= 0) {
        it     >>= shift;
        result += HEX_CHARS.charCodeAt(<i32>(it.lo & 15));
        shift  -= 4;
      }
    }

    return result;
  }
}