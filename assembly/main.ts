import { exp2f_lut } from "./exp2f";

export function exp2_lut(x: f32): f32 {
  return exp2f_lut(x);
}

export function expf(x: f32): f32 {
  return Mathf.exp(x);
}
