// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub struct Hello {
  lark: Vec<u8>
}

#[wasm_bindgen]
impl Hello {

  pub fn new() -> Hello {
    Hello { lark: vec![1,2,3,4,5,4,3,2,1] }
  }

  pub fn get(&self) -> Vec<u8> {
    self.lark.clone()
  }

}
