
@inline function fast_abs32(x: i32): i32 {
  var y = x >> 31;
  return (x ^ y) - y;
}

export function test1(x: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += abs(i);
  }
  return acc;
}

export function test2(x: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += fast_abs32(i);
  }
  return acc;
}
