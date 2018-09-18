// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub fn fib(n: u32) -> u32 {
    match n {
        0 | 1 => 1,
        _ => fib(n - 2) + fib(n - 1),
    }
}
