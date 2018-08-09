// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
  fn alert(s: i64);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn fibonacci(index: i8) {
  let mut prev = 1;
  let mut prevPrev = 0;
  let mut currentValue = 0;
  if index == 0 {
    alert(0);
    return;
  }
  for i in 1..index {
    prevPrev = prev;
    prev = currentValue;
    currentValue = prev + prevPrev;
  }
  alert(currentValue);
}
