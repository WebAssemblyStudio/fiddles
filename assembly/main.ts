 
export function imulOriginal(a: f64, b: f64): f64 {
  return Math.imul(a, b);
}

export function imulFixed(a: f64, b: f64): f64 {
  var x = <i32><i64>(a - 4294967296 * Math.floor(a * (1.0 / 4294967296)));
  var y = <i32><i64>(b - 4294967296 * Math.floor(b * (1.0 / 4294967296)));
  return x * y;
}

export function bench(): f64 {
  var acc = 0.0
  for (let i = 0; i < 10000000; i++) {
    acc += imulFixed(i & 1 ? 2.0 : -2.0, <f64>i);
  }
  return acc;
}