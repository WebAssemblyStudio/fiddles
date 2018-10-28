export function source(x: f64): f64 {
  return x / Math.LN2;
}

export function optimal(x: f64): f64 {
  return x * (1.0 / Math.LN2);
}
