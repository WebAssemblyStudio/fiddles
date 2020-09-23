

export function unopt(x: i32, y: i32, z: i32): bool {
  return x < y || x < z;
}

export function unopt2(x: i32, y: i32, z: i32): i32 {
  // @ts-ignore
  return i32(x < y) | i32(x < z);
}

export function opt(x: i32, y: i32, z: i32): bool {
  return x < min(y, z);
}
