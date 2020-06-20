

export function isPowOf2_1(x: u32): bool {
  return x != 0 & (x & (x - 1)) == 0;
}

export function isPowOf2_2(x: u32): bool {
  return popcnt(x) == 1;
}
