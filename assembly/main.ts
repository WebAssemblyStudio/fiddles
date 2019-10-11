export function test1(x: i32): i32 {
  return x * 8 / 3;
}

export function test2(x: i32): i32 {
  return <i32>(x * (8.0 / 3.0));
}
