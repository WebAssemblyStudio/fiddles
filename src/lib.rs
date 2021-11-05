// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

use std::io;

//https://benjaminbrandt.com/fibonacci-in-rust/
#[wasm_bindgen]
pub fn standardFibonacciInRust(n: u32) -> u32 {
    match n {
        0 => 1,
        1 => 1,
        _ => standardFibonacciInRust(n - 1) + standardFibonacciInRust(n - 2),
    }
}

//https://blog.graystorm.com/2020/07/22/somenumber-of-ways-to-calculate-a-fibonacci-number-in-rust/
#[wasm_bindgen]
pub fn betterDynamicFibonacciInRust(fib_num: u32) -> u32 {
    let mut memo = (0, 1);

    match fib_num {
        0 | 1 => fib_num,
        _ => {
            for _ in 2..=fib_num {
                memo = (memo.1, memo.0 + memo.1)
            }
            memo.1
        }
    }
}