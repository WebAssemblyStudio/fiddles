declare function log(x: i32): void;
declare function log16(x: u32, y: u32): void;

// const Pows10_64: u64[] = [
//   1,
//   10,
//   100,
//   1000,
//   10000,
//   100000,
//   1000000,
//   10000000,
//   100000000,
//   1000000000,

//   10000000000,
//   100000000000,
//   1000000000000,
//   10000000000000,
//   100000000000000,
//   1000000000000000,
//   10000000000000000,
//   100000000000000000,
//   1000000000000000000,
//   10000000000000000000,
// ];

// function digits10(value: u64): i32 {
//   var l = 64 - <i32>clz(value); // log2
//   var t = l * 1233 >>> 12;      // l / lg2
//       t = t - <i32>(value < unchecked(Pows10_64[t]));
//   return t + 1;
// }

// log(digits10(-1));



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

export function div10(value: i32): i32 {
  return value / 10;
}

export function div10_2(value: i32): i32 {
  var invDivisor: i64 = 0x1999999A;
  return <i32>((invDivisor * value) >> 32);
}

log(div10(i32.MAX_VALUE));
log(div10_2(i32.MAX_VALUE));