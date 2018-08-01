// Current prelude for using `wasm_bindgen`
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) -> String {
    format!("Hello, {}!", name)
}

#[wasm_bindgen]
pub fn sieve(n: u32) -> Vec<u32> {
  let max: u32 = (n as f64).sqrt() as u32 + 1;
  let mut arr = 2..n + 1;
  let mut cand = 2;
  while cand < max {
    arr = arr.map(|&i| match i % cand == 0 && i != cand { true => 0, false => 1 } );
    cand = arr.find(|&i| i > cand).unwrap_or_else(cand + 1);
  }
  arr.filter(|i| i > 1).collect::<Vec<u32>>()
}