

function leibnizPow(i: f64): f64 {
  return Math.pow(-1.0, i) / (2.0 * i + 1.0);
}

export function leibniz(n: f64): f64 {
  let r: f64 = .0;
  for (let i: f64; i < n; i++) {
    r += leibnizPow(i);
  }
  return 4.0 * r;
}

