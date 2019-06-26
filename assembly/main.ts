export function adding(x: i32, d: f32): f32 {
  let sum: f32 = 0;
  for (let i:i32 = 0; i <= x; i++) {
    sum += (i as f32)* d;
  }
  return sum;
}
