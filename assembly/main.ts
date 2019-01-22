 
export function imulOriginal(a: f64, b: f64): f64 {
  return Math.imul(a, b);
}

export function imulFixed(a: f64, b: f64): f64 {
  // TODO use saturation operations if it support
  a = max(min(a, f64.MAX_SAFE_INTEGER + 1), -f64.MAX_SAFE_INTEGER - 1);
  b = max(min(b, f64.MAX_SAFE_INTEGER + 1), -f64.MAX_SAFE_INTEGER - 1);
  return <f64><i32>(<i64>a * <i64>b);
}