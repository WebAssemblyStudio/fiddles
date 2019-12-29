import { powf_lut } from "./math"

export function new_powf(): f32 {
  var acc: f32 = 0
  for (let z = 0; z < 20; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        acc += powf_lut(x as f32, y as f32);
      }
    }
  }
  return acc;
}

export function old_powf(): f32 {
  var acc: f32 = 0
  for (let z = 0; z < 20; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        acc += Mathf.pow(x as f32, y as f32);
      }
    }
  }
  return acc;
}
