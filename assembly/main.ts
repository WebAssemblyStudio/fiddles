

export function test(c: u32, a: u8): u32 {
  let factor: f32 = a ? 0xFF / f32(a) : 1;
  let b = f32(c >> 24 & 0xFF) * factor;
  let g = f32(c >> 16 & 0xFF) * factor;
  let r = f32(c >>  8 & 0xFF) * factor;
  return (
    (u32(a) & 0xFF) << 24 | 
    (u32(b) & 0xFF) << 16 | 
    (u32(g) & 0xFF) <<  8 | 
    (u32(r) & 0xFF) <<  0
  );
}
