export function sum(from: i32, to: i32): f64 {
  let total = 0.0;
  for (let i = from; i < to; i++) {
    total += load<f64>(i << 3);
  }
  return total;
}
