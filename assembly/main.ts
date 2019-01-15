
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

@inline function clamp255(x: i32): i32 {
  // return (((255 - x) >> 31) | (x & ~(x >> 31))) & 255;
  return ((~(x >> 31)) & (((255 - x) >> 31) | x)) & 255;
}



export function test1(x: i32, y: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += min(max(i, 0), 255);
  }
  return acc;
}


export function test2(x: i32, y: i32): i32 {
  let acc = 0;
  for (let i = -10000000; i < 10000000; ++i) {
    acc += clamp255(i);
  }
  return acc;
}
