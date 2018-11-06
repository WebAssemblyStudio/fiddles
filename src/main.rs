#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
#[no_mangle]
pub fn includes(a: &str, b: &str) -> bool {
    a.contains(b)
}