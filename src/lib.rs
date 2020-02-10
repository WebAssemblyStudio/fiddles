// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn sum(numA: f64, numB:f64)->f64{
    numA+times(numB)
}

fn times(num: f64) -> f64 {
  num + 2.0
}

#[wasm_bindgen]
pub fn minus(numA : f64, numB : f64) -> f64 {
  numA - numB
}