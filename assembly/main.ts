export function test(): f64 {
  var acc = 0.0;
  for (let i: f64 = 0; i < 10000000.0; ++i) {
    acc += (i * 10000.0) % i;
  }
  return acc;
}
