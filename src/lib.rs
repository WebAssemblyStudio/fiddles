#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

struct Struct {
    a: u32,
    b: u32,
}

enum Enum {
    A(u32),
    B(f64),
}

extern {
    fn struct_(t: Struct);
    fn enum_(e: Enum);
}

#[wasm_bindgen]
pub fn main() {
    unsafe {
        struct_(Struct {a: 123, b: 456});
        enum_(Enum::A(123));
        enum_(Enum::B(456.789));
    }
}
