// export function test2(n: i64): i64 { // 90
//   return <i64><i32>n;
// }

// export function test3(n: i64): i64 { // 90
//   return n << 32 >> 32;
// }

export function test4(n: i64): u64 { // 90
  return <u64><u32>n;
}

export function test5(n: i64): u64 { // 95
  return n & 0xFFFFFFFF;
}
