
export function idiv(x: i64, y: i64): i64 {
  // 0x1FFFFFFFFFFFFF: 2 ** 52 - 1
  if (((x | y) & ~0x1FFFFFFFFFFFFF) == 0) {
    return (f64(x) / f64(y)) as i64;
  }
  return x / y;
}

export function udiv(x: u64, y: u64): u64 {
  // 0x1FFFFFFFFFFFFF: 2 ** 52 - 1
  if (((x | y) & ~0x1FFFFFFFFFFFFF) == 0) {
    return (f64(x) / f64(y)) as u64;
  }
  return x / y;
}

// export function idiv2(x: i64, y: i64): i64 {
//   return x / y;
// }

// export function udiv2(x: u64, y: u64): u64 {
//   return x / y;
// }
