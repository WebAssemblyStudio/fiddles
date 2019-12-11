import { pow_lut } from "./math"

export function new_pow(x: f64, y: f64): f64 {
  return pow_lut(x, y);
}

export function old_pow(x: f64, y: f64): f64 {
  return Math.pow(x, y);
}
