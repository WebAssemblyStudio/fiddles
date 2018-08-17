#![feature(custom_attribute)]
#![feature(repr_transparent)]
use std::ffi::CString;
use std::os::raw::c_char;

#[wasm_bindgen]
#[no_mangle]
pub fn fib(n: i32) -> i32{
    match n {
        0 => 0,
        1 => 1,
        _ => fib(n-1) + fib(n-2),
    }
}