
declare function log(x: i32): void;

@inline function fast_min32(x: i32, y: i32): i32 {
  // return y ^ (x ^ y) & <u32>(-(x < y));
  let d = x - y;
  return y + (d & (d >> 31));
}

export function test1(y: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += min(i, y);
  }
  return acc;
}

export function test2(y: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += fast_min32(i, y);
  }
  return acc;
}
