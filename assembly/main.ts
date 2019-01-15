
declare function log(x: i32): void;

@inline function fast_min32(x: i32, y: i32): i32 {
  return y ^ (x ^ y) & -(x < y);
}

export function test1(x: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += min(i, 0);
  }
  return acc;
}

export function test2(x: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += fast_min32(i, 0);
  }
  return acc;
}
