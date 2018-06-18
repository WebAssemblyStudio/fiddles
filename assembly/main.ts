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

export function div10(value: i32): i32 {
  return value / 10;
}