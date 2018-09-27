// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
}

#[wasm_bindgen]
pub fn isFullWidth(charCode: i32) -> bool {
  let result: bool = (charCode >= 0x2E80 && charCode <= 0xD7AF) || (charCode >= 0xF900 && charCode <= 0xFAFF) || (charCode >= 0xFF01 && charCode <= 0xFF5E);

  result
}