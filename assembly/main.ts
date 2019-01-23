 
export function imulOriginal(a: f64, b: f64): f64 {
  return Math.imul(a, b);
}

function wrap(a: f64): f64 {
  return abs(a) >= 4294967296 ? (a - 4294967296 * floor(a * (1.0 / 4294967296))) : a;
}

export function imulFixed(a: f64, b: f64): f64 {
  // var x = abs(a) >= 4294967296 ? (a - 4294967296 * Math.floor(a * (1.0 / 4294967296))) : a;
  // var y = abs(b) >= 4294967296 ? (b - 4294967296 * Math.floor(b * (1.0 / 4294967296))) : b;
  // return <i32><i64>x * <i32><i64>y;
  return wrap(wrap(a) * wrap(b));
}