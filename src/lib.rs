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

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
    let mut this_is_an_array: Vec<i64> = vec![];
    for i in 0..100203 {
      this_is_an_array.push(i * 77777 >> 25 | 2223344);
    }
    alert(&format!("Hello, {}!", this_is_an_array[9205]));
}
