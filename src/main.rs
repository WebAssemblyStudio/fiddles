#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub fn includes_static_for_1000_times() {
  for i in 0..10000 {
  "helloWorld".contains("hello");
  }
}
