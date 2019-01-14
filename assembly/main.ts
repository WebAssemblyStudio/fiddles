

export function test1(x: i32): i32 {
  return abs(x);
}

export function test2(x: i32): i32 {
  var y = x >> 31;
  return (x ^ y) - y;
}
