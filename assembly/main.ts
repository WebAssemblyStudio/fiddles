import { pow_lut } from "./math"

export function new_pow(): f64 {
  var acc = 0.0
  for (let y = 1e-300; y <= 1e+308; y *= 2.0) {
    for (let x = 1e-300; x <= 1e+308; x *= 2.0) {
      acc += pow_lut(x, y);
    }
  }
  return acc;
}

export function old_pow(): f64 {
  var acc = 0.0
  for (let y = 1e-300; y <= 1e+308; y *= 2.0) {
    for (let x = 1e-300; x <= 1e+308; x *= 2.0) {
      acc += Math.pow(x, y);
    }
  }
  return acc;
}
