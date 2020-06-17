
export function a(v: i32): bool {
  return bool(v >>> 31);
}

export function b(v: i32): bool {
  return v < 0;
}