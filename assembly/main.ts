import "allocator/arena";

declare namespace console {
  function logv(lo1: u32, lo2: u32, hi1: u32, hi2: u32): void;
}

class u128 {
  constructor(
    public lo: u64 = 0,
    public hi: u64 = 0,
  ) {}

  @inline @operator('|')
  static or(a: u128, b: u128): u128 {
    return new u128(a.lo | b.lo, a.hi | b.hi);
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
    var hi = lo & ~mod2;

    hi |= ((value.hi << shift64) | ((vl >> (64 - shift64)) & mod1)) & mod2;

    return new u128(lo & mod2, hi);
  }

  @inline @operator('>>')
  static shr(value: u128, shift: i32): u128 {
    shift &= 127;

    // need for preventing redundant i32 -> u64 extends
    var shift64: u64 = shift;

    var mod1: u64 = ((((shift64 + 127) | shift64) & 64) >> 6) - 1;
    var mod2: u64 = (shift64 >> 6) - 1;

    shift64 &= 63;

    var vh = value.hi;
    var hi = vh >> shift64;
    var lo = hi & ~mod2;

    lo |= ((value.lo >> shift64) | ((vh << (64 - shift64)) & mod1)) & mod2;

    return new u128(lo, hi & mod2);
  }

  @inline
  static rotr(value: u128, shift: i32): u128 {
    // shift &= 127;
    // if (shift ==  0) return this.clone();
    // if (shift == 64) return new u128(value.hi, value.lo);
    // TODO optimize this
    // return u128.shr(value, shift) | u128.shl(value, 128 - shift);

    shift &= 127;
    var shift64: u64 = 128 - shift;

    var mod1: u64 = ((((shift64 + 127) | shift64) & 64) >> 6) - 1;
    var mod2: u64 = (shift64 >> 6) - 1;

    shift64 &= 63;

    var vl = value.lo;
    var vh = value.hi;
    var lo1 = vl << shift64;
    var hi1 = lo1 & ~mod2;

    hi1 |= ((vh << shift64) | ((vl >> (64 - shift64)) & mod1)) & mod2;
    lo1 &= mod2;

    shift64 = shift;

    mod1 = ((((shift64 + 127) | shift64) & 64) >> 6) - 1;
    mod2 = (shift64 >> 6) - 1;

    shift64 &= 63;

    var hi2 = vh >> shift64;
    var lo2 = hi2 & ~mod2;

    lo2 |= ((vl >> shift64) | ((vh << (64 - shift64)) & mod1)) & mod2;
    hi2 &= mod2;

    return new u128(lo1 | lo2, hi1 | hi2);
  }
}

function log(val: u128): void {
  console.logv(<u32>(val.lo & 0xFFFFFF), <u32>(val.lo >> 32), <u32>(val.hi & 0xFFFFFF), <u32>(val.hi >> 32));
}

var t = new u128(0x2000000000000001, 0x5000000000000003);

log(t);
log(u128.rotr(t, 64));

