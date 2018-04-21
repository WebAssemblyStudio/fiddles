// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub struct Data {
  value: i32
}

#[wasm_bindgen]
impl Data {
  pub fn new(value: i32) -> Data {
    Data{ value }
  }
  pub fn getValue(&mut self) -> i32{
    self.value
  }
}

