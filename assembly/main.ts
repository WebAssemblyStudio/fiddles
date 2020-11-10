export function sat_conv_rust(x: f64): u32 {
  const upper = reinterpret<f64>(0x41EFFFFFFFE00000);
  if (x <= 0.0) return 0;
  return select(x as u32, -1, x <= upper);
}

export function sat_conv_opt(x: f64): u32 {
  const upper = reinterpret<f64>(0x41EFFFFFFFE00000);
  return min(max(x, 0.0), upper) as u32;
}
