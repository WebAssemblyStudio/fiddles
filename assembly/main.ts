

export function original(): f64 {
  var acc = 0.0;
  for (let x = 1e-60; x < 1e60; x += 5.0) {
    acc += Math.exp(x) * 1e-60;
  }
  return acc;
}
