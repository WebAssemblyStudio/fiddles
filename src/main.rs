#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub extern "C" fn add(a: i32, b: i32) -> str {
    return "pippo";
    //return a + b;
}
