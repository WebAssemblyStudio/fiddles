#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;
use std::ffi::CString;
use std::os::raw::c_char;

static HELLO: &'static str = "Hello, World!";

#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

#[no_mangle]
pub extern "C" fn hello_world() -> *mut c_char {
    let s = CString::new(HELLO).unwrap();
    s.into_raw()
}

#[no_mangle]
pub extern "C" fn hello_world_len() -> usize {
  HELLO.len()
}

#[wasm_bindgen]
pub fn generate_greeting() -> String {
    "Hello, world!".to_string()
}