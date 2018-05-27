// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
    fn appendToBody(n: u32);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
}

#[wasm_bindgen]
pub fn mewo(who: String) -> String {
  appendToBody(420);
  format!("hello, {}", who)
}

#[wasm_bindgen]
pub fn dej_arej() -> Vec<u32> {
  vec![1, 2, 3]
}

#[wasm_bindgen]
pub fn wez_numer(a: u32) -> u32 {
  a + 1
}
