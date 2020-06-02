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

const R: usize = 0;
const G: usize = 1;
const B: usize = 2;
const A: usize = 3;

#[wasm_bindgen]
pub fn init_img(img: &mut [u8], height: usize, width: usize) {
  /*
  assert!(img.len() == 4*height*width);
  for y in 0..height {
    for x in 0..width {
      let i = y*x*4;
      let pixel = &mut img[i..i+4];
      pixel[R] = 0;
      pixel[G] = 0;
      pixel[B] = 0;
      pixel[A] = 0xff;
    }
  }
  */
}


// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
}
