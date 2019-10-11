

export function abs1(t: i32): i32 {
  return select(-t, t, t >>> 31);
}

export function abs2(t: i32): i32 {
  return abs(t);
}
