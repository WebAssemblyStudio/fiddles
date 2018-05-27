// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub fn hello(greeting: String, number: u32) -> String {
  let answer = number * 2;
  format!("
    <p>
      {} from wasm! the answer is {}!
    </p>
  ", greeting, answer)
}
