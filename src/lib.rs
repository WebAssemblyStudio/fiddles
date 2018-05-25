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

#[wasm_bindgen(module = "./main")]
extern {
  fn addCallback(res: AddResult);
}

#[wasm_bindgen]
pub struct AddResult {
  a: i32,
  b: i32,
}

#[wasm_bindgen]
impl AddResult {
  pub fn a(&self) -> i32 {
    self.a
  }

  pub fn b(&self) -> i32 {
    self.b
  }

  pub fn to_result(&self) -> i32 {
    self.a + self.b
  }
}

#[wasm_bindgen]
pub fn add(a: i32, b: i32) {
  addCallback(AddResult { a, b });
}