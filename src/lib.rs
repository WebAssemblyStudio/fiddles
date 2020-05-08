// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
  fn alert(s: &str);
  fn fake(d: &[u8]);
  fn updateFrame(d: &[u8]);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
  alert(&format!("Hello {}!", name));
}

#[wasm_bindgen]
pub fn drawFrame() {
  let mut rawframe = [255; 128*128*4];
  let mut i = 0;
  while i < 128*128*4 {
    rawframe[i] = 0;
    i += 4;
  }
  updateFrame(&rawframe);
}