


class Foo {
  @inline
  static shl(x: u64, shift: i32): u64 {
    shift &= 127;

    var mod1: u64 = ((((shift + 127) | shift) & 64) >> 6) - 1;
    var mod2: u64 = (shift >> 6) - 1;

    shift &= 63;

    return (x & mod1) + ((x << 32) & mod2);
  }
}

export function foo(a: u64): u64 {
  return Foo.shl(a, 1);
}
