import { powf_lut } from "./math"

export function new_powf(x: f32, y: f32): f32 {
  return powf_lut(x, y);
}

export function old_powf(x: f32, y: f32): f32 {
  return Mathf.pow(x, y);
}
