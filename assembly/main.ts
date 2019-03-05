
declare function __log(v: f64): void;

export function __umulh64_1(u: u64, v: u64): u64 {
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

export function __umulh64_2(u: u64, v: u64): u64 {
  return (u << 32) * (v << 32);
}


function log(v: u64): void {
  __log(reinterpret<f64>(v));
}

log(__umulh64_1(0x123, 0xFFFFFFFFFFFFFFFF));
log(__umulh64_2(0x123, 0xFFFFFFFFFFFFFFFF));