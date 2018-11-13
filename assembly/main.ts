
export function test1(): f64 {
  var acc = 0.0;
  for (let b = -100.0, p = -1000000.0; b < 100.0; b += 0.00001, p += 0.1) {
    acc += Math.pow(b, p);
  }
  return acc;
}

@inline
function fastPow(x: f64, y: f64): f64 {
  return Math.exp(y * Math.log(x));
}

export function test2(): f64 {
  var acc = 0.0;
  for (let b = -100.0, p = -1000000.0; b < 100.0; b += 0.00001, p += 0.1) {
    acc += fastPow(b, p);
  }
  return acc;
}
