

// 193 bytes
function rev2(x: u32): u32 {
   x = (x & 0x55555555) <<  1 | (x >>  1) & 0x55555555;
   x = (x & 0x33333333) <<  2 | (x >>  2) & 0x33333333;
   x = (x & 0x0F0F0F0F) <<  4 | (x >>  4) & 0x0F0F0F0F;
   x = (x << 24) | ((x & 0xFF00) << 8) |
       ((x >> 8) & 0xFF00) | (x >> 24);
   return x;
}

// 167 bytes
function rev11(x: u32): u32 {
   x = x | ((x & 0x000000FF) << 16);
   x = (x & 0xF0F0F0F0) | ((x & 0x0F0F0F0F) << 8);
   x = (x & 0xCCCCCCCC) | ((x & 0x33333333) << 4);
   x = (x & 0xAAAAAAAA) | ((x & 0x55555555) << 2);
   x = x >> 15;
   return x;
}

// 164 bytes
function rev11a(x: u32): u32 {
   let t: u32;
   x = x | ((x & 0x000000FF) << 16);
   t = x & 0x0F0F0F0F; x = (t <<  8) | (t ^ x);
   t = x & 0x33333333; x = (t <<  4) | (t ^ x);
   t = x & 0x55555555; x = (t <<  2) | (t ^ x);
   x = x >> 15;
   return x;
}

// 175 bytes
function rev12(x: u32): u32 {
   x = rotl(x & 0x00FF00FF, 16) | x & ~0x00FF00FF;
   x = rotl(x & 0x0F0F0F0F,  8) | x & ~0x0F0F0F0F;
   x = rotl(x & 0x33333333,  4) | x & ~0x33333333;
   x = rotl(x & 0x55555555,  2) | x & ~0x55555555;
   x = rotl(x, 1);
   return x;
}

const ITER: u32 = 10_000_000;

export function bench_rev2(): u32 {
  let acc = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev2(i);
  }
  return acc;
}

export function bench_rev11(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev11(i);
  }
  return acc;
}

export function bench_rev11a(): u32 {
  let acc = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev11a(i);
  }
  return acc;
}

export function bench_rev12(): u32 {
  let acc: u32 = 0;
  for (let i: u32 = 0; i < ITER; i++) {
    acc += rev12(i);
  }
  return acc;
}
