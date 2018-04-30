#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub struct Data(String);

#[wasm_bindgen]
impl Data {

  pub fn new(value: &str) -> Data {
    Data(value.to_owned())
  }

  pub fn repeat(&mut self, count: i32) -> String {
    (0..count)
      .into_iter()
      .map(|_| {
        self.0.clone()
      })
      .collect::<Vec<String>>()
      .concat()
  }
}

