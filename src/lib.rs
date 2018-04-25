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

#[wasm_bindgen]
pub struct Hello {
  lark: Vec<u8>
}

#[wasm_bindgen]
impl Hello {

  pub fn new() -> Hello {
    Hello { lark: vec![1,2,3,4,5,4,3,2,1] }
  }

  pub fn sort(&mut self) {
    self.lark.sort()
  }

  pub fn get(&self) -> Vec<u8> {
    self.lark.clone()
  }

}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
}
