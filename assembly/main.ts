 
export function imulOriginal(a: f64, b: f64): f64 {
  return Math.imul(a, b);
}

export function imulFixed(a: f64, b: f64): f64 {
  // TODO use saturation operations if it support
  // a = max(min(a, f64.MAX_SAFE_INTEGER + 1), -f64.MAX_SAFE_INTEGER - 1);
  // b = max(min(b, f64.MAX_SAFE_INTEGER + 1), -f64.MAX_SAFE_INTEGER - 1);
  // var x = <i32><i64>(a % 4294967296);
  // var y = <i32><i64>(b % 4294967296);
  var x = <i32><i64>(a - 4294967296 * Math.floor(a * (1.0 / 4294967296)));
  var y = <i32><i64>(b - 4294967296 * Math.floor(b * (1.0 / 4294967296)));
  return x * y;
}