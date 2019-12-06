// import { exp2f_lut } from "./exp2f";

// export function exp2_lut(x: f32): f32 {
//   return exp2f_lut(x);
// }

// export function expf(x: f32): f32 {
//   return Mathf.exp(x);
// }

// import { logf_lut } from "./logf";

// export function log_lut(x: f32): f32 {
//   return logf_lut(x);
// }

// export function logf(x: f32): f32 {
//   return Mathf.log(x);
// }

// import { expf_lut } from "./expf";

// export function exp_lut(x: f32): f32 {
//   return expf_lut(x);
// }

// export function expf(x: f32): f32 {
//   return Mathf.exp(x);
// }

// import { powf_lut } from "./powf";

// export function pow_lut(x: f32, y: f32): f32 {
//   return powf_lut(x, y);
// }

// export function powf(x: f32, y: f32): f32 {
//   return Mathf.pow(x, y);
// }

import { log2_lut } from "./log2";

export function log2_new(x: f64): f64 {
  return log2_lut(x);
}

export function log2(x: f64): f64 {
  return Math.log2(x);
}