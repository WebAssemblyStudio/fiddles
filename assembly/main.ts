
@inline
function precompute(y: f64): f64 {
  let z1 = 1.0 / y;
  let e  = 1.0 - y * z1;
  let z2 = z1 + z1 * e;
  let e1 = e  * e;
  let z3 = z2 + z2 * e1;
  let e2 = e1 * e1;
  let z  = z3 + z3 * e2;
  return z;
}

@inline
function divconst(x: f64, y: f64, z: f64): f64 {
  let q1 = x * z;
  let r  = x  - y * q1;
  let q  = q1 + r * z;
  return q;
}

var ln2Z = precompute(Math.LN2);

export function precomputedConstDiv(): f64 {
  let acc = 0.0;
  let z = ln2Z;
  for (let x: f64 = 0; x < 100000.0; x += 0.1) {
    acc += divconst(x, Math.LN2, z);
  }
  return acc;
}

export function originalConstDiv(): f64 {
  let acc = 0.0;
  for (let x: f64 = 0; x < 100000.0; x += 0.1) {
    acc += x / Math.LN2;
  }
  return acc;
}
