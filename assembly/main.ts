function test1(x: i64): i32 {
    return x < 0 ? -1 : 1;
}

function test2(x: i64): i32 {
    return i32(x >> 63) | 1; // shrink 1 byte
}

const ITERS = 10_0000_0000;

export function bench1(): i32 {
  let acc = 0;
  for (let i = -ITERS; i < ITERS; i++) {
    acc += test1(i as i64);
  }
  return acc;
}

export function bench2(): i32 {
  let acc = 0;
  for (let i = -ITERS; i < ITERS; i++) {
    acc += test2(i as i64);
  }
  return acc;
}