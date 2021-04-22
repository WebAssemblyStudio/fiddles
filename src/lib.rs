#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub fn mul_add(a: f64, b: f64, c: f64) -> f64 {
  f64::mul_add(a, b, c)
}