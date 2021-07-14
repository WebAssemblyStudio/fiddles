// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

use std::os::raw::c_char;
use std::ffi::{CString};

fn main() {}

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
}


// Here we're exporting a function called `fact` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn fact(mut n: u32) -> u32 {
    let mut result = 1;
    while n > 0 {
        result = result * n;
        n = n - 1;
    }
    return result;
}

#[wasm_bindgen]
pub fn fact_str(n: u32) -> *mut c_char {
    let default_value: i8 = 0;
    if n > 20 {
      alert(&format!("El número {} no puede ser calculado! debe ser menor a 20", n));
      return default_value as *mut i8;
    }
    let res = fact(n);
    let s = format!("{}", res);
    let s = CString::new(s).unwrap();
    s.into_raw()
}