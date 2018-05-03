// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

fn fac(n: i32) -> i32 {
  if n < 2 {
    return 1;
  }
  n * fac(n - 1)
}

#[wasm_bindgen]
pub fn app() -> i32 {
    fac(6)
}
