export function test(ly: u32, iy: i32, k: i32): u32 {
  k = (iy >> 20) - 0x3FF;
  let offset = (k > 20 ? 52 : 20) - k;
  let Ly = k > 20 ? ly : iy;
  let jj = Ly >> offset;
  return jj;
}
