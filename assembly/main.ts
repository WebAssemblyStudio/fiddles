

export function test(c: u32, factor: f32): f32 {
  let t = <u8>(c >> 24) * factor;
  return t;
}
