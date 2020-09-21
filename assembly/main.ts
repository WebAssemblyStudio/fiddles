

export function test(c: u32, a: u8): u32 {
  let factor: f32 = a ? 0xFF / <f32>a : 1;
  let b = f32(c >> 24 & 0xFF) * factor;
  let g = f32(c >> 16 & 0xFF) * factor;
  let r = f32(c >>  8 & 0xFF) * factor;
  return (
    <u32><u8>a << 24 | 
    <u32><u8>b << 16 | 
    <u32><u8>g <<  8 | 
    <u32><u8>r <<  0
  );
}
