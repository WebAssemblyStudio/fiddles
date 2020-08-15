

// export function div(x: i32, y: i32): i32 {
//   return x - (y - x);
// }

// export function ext1(x: i32): i32 {
//   return x as i64 as i32; // -> x
// }

// export function ext2(x: u64, y: u32): u64 {
//   return x as u32 as u64; // -> x & 0xFFFFFFFF
// }

export function ext3(x: i64, y: u32): i64 {
  return x as i32 as i64; // -> x << 32 >> 32
}

export function ext3opt(x: i64, y: u32): i64 {
  return x << 32 >> 32; 
}
