#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub extern "C" fn sum(a: i32, b: i32) -> i32 {
    return a + b;
}

use std::ffi::CString;
use std::os::raw::c_char;

static HELLO: &'static str = "hello from rust";

#[no_mangle]
pub fn get_hello() -> *mut c_char {
    let s = CString::new(HELLO).unwrap();
    s.into_raw()
}

#[no_mangle]
pub fn get_hello_len() -> usize {
    HELLO.len()
}