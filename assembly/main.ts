

export function rem256s(a: i32): i32 {
  return a % 256;
}

export function rem256s_opt(a: i32): i32 {
  return a - (((a >> 31 & 255) + a) & ~255);
  // return (a & 255) | ((a >> 31) & ~255);
}
