

export function t1(x: u64): bool {
  return (x & 1) == 1;
}

export function t2(x: u64): i32 {
  return i32(x & 1);
}
