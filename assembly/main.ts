import "allocator/arena";

declare function sayHello(): void;

class u128 {

  constructor(
    public lo: u64 = 0,
    public hi: u64 = 0,
  ) {}

  @inline
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

    hi |= value.hi << shift64;
    hi |= (vl >> (64 - shift64)) & mod1;

    return new u128(lo & mod2, hi & mod2);
  }
}

export function foo(): u64 {
  var t = new u128(100, 100);
  return u128.shl(t, 1).lo;
}

export function foo2(): u64 {
  var t = new u128(100, 100);

  var vl = t.lo;
  var lo = vl << 1;
  var hi = (t.hi << 1) | (vl >> 63);

  var r = new u128(lo, hi);
  return r.lo;
}

export function foo3(value: u64): u64 {
  var shift64: u64 = 1;
  var mod2: u64 = (shift64 >> 6) - 1;

  var vl = value;
  var lo = vl << shift64;
  var hi = lo & ~mod2;
  return lo + hi;
}