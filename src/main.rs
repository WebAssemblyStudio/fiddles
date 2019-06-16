#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

use std::ffi::CString;
use std::os::raw::c_char;

#[no_mangle]
pub extern "C" fn getWelcomeMessage() -> *mut c_char {
    CString::new("Hello from Rust!")
        .unwrap()
        .into_raw()
}

#[wasm_bindgen]
pub fn greet(name: &str) -> String {
    format!("Hello, {}!", name)
}

extern {
    fn logResult(i: i32);
}

#[no_mangle]
pub extern "C" fn dealloc_str(ptr: *mut c_char) {
    unsafe {
        let _ = CString::from_raw(ptr);
    }
}


#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    unsafe {
        logResult(x + 3);
    }
    x
}