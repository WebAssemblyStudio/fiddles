export function decimalCount32_old(value: u32): u32 {
  if (value < 100000) {
    if (value < 100) {
      return select<u32>(1, 2, value < 10);
    } else {
      let m = select<u32>(4, 5, value < 10000);
      return select<u32>(3, m, value < 1000);
    }
  } else {
    if (value < 10000000) {
      return select<u32>(6, 7, value < 1000000);
    } else {
      let m = select<u32>(9, 10, value < 1000000000);
      return select<u32>(8, m, value < 100000000);
    }
  }
}

export function decimalCount32_new(value: u32): u32 {
  if (value < 100000) {
    if (value < 100) {
      return 1 + i32(value >= 10);
    } else {
      return 3 + u32(value >= 10000) + u32(value >= 1000);
    }
  } else {
    if (value < 10000000) {
      return 6 + u32(value >= 1000000);
    } else {
      return 8 + u32(value >= 1000000000) + u32(value >= 100000000);
    }
  }
}
