

export function isInteger(x: f64): bool {
  return trunc(x) == x && isFinite(x);
}

export function t2(x: f64): bool {
  return x == trunc(x) && isFinite(x);
}
