
export function float2int(x: f32): i32 {
  return reinterpret<i32>(x);
}

export function int2float(x: i32): f32 {
  return reinterpret<f32>(x);
}