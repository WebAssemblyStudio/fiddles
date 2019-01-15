export function clamp(x: i32): i32 {
  return min(max(x, 0), 255);
}

export function clamp2(x: i32): i32 {
  return ~(x >> 31) & (((255 - x) >> 31) | x);
}

