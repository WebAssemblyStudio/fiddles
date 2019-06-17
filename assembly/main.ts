
export function sigmoid(x: f64): f64 {
  return 1 / (1 + Math.exp(-x))
}