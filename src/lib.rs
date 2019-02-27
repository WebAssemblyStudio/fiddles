#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
//Load modules
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

//Import JavaScript things into Rust and export Rust things to JavaScript.
// Export a `sum` function from Rust to JavaScript
#[wasm_bindgen]
pub fn sum(numA: f64, numB: f64)->f64{
    numA + numB
}