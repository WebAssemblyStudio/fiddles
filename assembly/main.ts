// export function mod(x: u32): i32 {
//   return x % -1;
// }

export function diff(x: i32, y: i32): i32 {
  if (x > y) {
    return x - y;
  } else {
    return y - x;
  }
}

export function diff2(x: i32, y: i32): i32 {
  return abs(x - y);
}

