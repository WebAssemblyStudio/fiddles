// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub fn sum_from_one_to_n(num: &str) -> i32 {
    let n: i32 = num.trim().parse().expect("Error");
    let mut sum = 0;
    for i in 1..n + 1 {
        sum += i;
    }
    sum
}