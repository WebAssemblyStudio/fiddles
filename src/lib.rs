// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
extern crate num;
use wasm_bindgen::prelude::*;
use num::BigRational;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    #[wasm_bindgen(namespace = "console")]
    fn log(s: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn firstx_fibonacci(x: u64) {
  let mut a = BigRational::from_integer(0);
  let mut b = BigRational::from_integer(1);

  for _ in 1..=x {
    use std::mem;
    b += mem::replace(&mut a, b);
    log(&format("{}", b));
  }
}