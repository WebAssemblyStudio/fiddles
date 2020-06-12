
@inline
function umulh(a: u64, b: u64): u64 {
  var u0 = a & 0xFFFFFFFF;
  var u1 = a >> 32;
  var v0 = b & 0xFFFFFFFF;
  var v1 = b >> 32;

  var l = u0 * v0;
  var t = u1 * v0 + (l >> 32);
  var w = u0 * v1 + (t & 0xFFFFFFFF);

  return u1 * v1 + (t >> 32) + (w >> 32);
}

export function div100_1(x: f64): f64 {
  return f64(u64(x) / 100);
}

export function div100_2(x: f64): f64 {
  return f64(umulh(u64(x) >> 2, 0x28F5C28F5C28F5C3) >> 2);
}

