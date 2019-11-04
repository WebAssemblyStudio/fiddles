

export function test1(x: i64): i32 {
  if (x != 0) return 1;
  return 0;
}

export function test2(x: i64): i32 {
  if (!!x) return 1;
  return 0;
}
