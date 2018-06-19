@inline
export function __umulh64(u: u64, v: u64): u64 {
  var u0 = u & 0xFFFFFFFF;
  var v0 = v & 0xFFFFFFFF;

  var u1 = u >> 32;
  var v1 = v >> 32;

  var l = u0 * v0;
  var t = u1 * v0 + (l >> 32);
  var w = u0 * v1 + (t & 0xFFFFFFFF);

  t >>= 32;
  w >>= 32;

  return u1 * v1 + t + w;
}

@inline
function div_1e10(value: u64): u64 {
  return __umulh64(value, 0x1b7cdfd9d7bdbc >> 13) >> 9;
}

@inline
function div_1e10_norm(value: u64): u64 {
  return value / <u64>(10000000000);
}

export function test1(): u32 {
  let result: u64 = 0;
  for (let i: u64 = 10000000000; i < 10100000000; i++) {
    result = div_1e10(i);
  }
  return <u32>result;
}

export function test2(): u32 {
  let result: u64 = 0;
  for (let i: u64 = 10000000000; i < 10100000000; i++) {
    result = div_1e10_norm(i);
  }
  return <u32>result;
}

/*
log(<f64>div_1e10(18446744073709551615));
log(<f64>(<u64>(18446744073709551615) / <u64>(10000000000)));
*/