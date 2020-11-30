export function uopt(x: f32, y: f32): u32 {
  return reinterpret<u32>(x + (-y));
}

export function opt(x: f32, y: f32): u32 {
 return reinterpret<u32>(x - y);
}
