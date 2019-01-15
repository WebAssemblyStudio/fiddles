
declare function log(x: i32): void;

@inline function fast_min32(x: i32, y: i32): i32 {
  // return y ^ (x ^ y) & <u32>(-(x < y));
  let d = x - y;
  return y + (d & (d >> 31));
}

@inline function fast_max32(x: i32, y: i32): i32 {
  // return y ^ (x ^ y) & <u32>(-(x < y));
  let d = x - y;
  return x - (d & (d >> 31));
}

@inline function clamp(x: i32, a: i32, b: i32): i32 {
  let d = x - a;
  d = (d & (d >> 31)) + (a - b);
  return b + (d & (d >> 31));
}

export function test1(x: i32, y: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += min(max(i, 0), 100);
  }
  return acc;
}

export function test2(x: i32, y: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += fast_min32(fast_max32(i, 0), 100);
  }
  return acc;
}

export function test3(x: i32, y: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += clamp(i, 0, 100);
  }
  return acc;
}
