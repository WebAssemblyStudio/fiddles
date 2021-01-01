// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn eval(s: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn log(jscode: &str) {
    eval(&format!("{}", jscode));
}
