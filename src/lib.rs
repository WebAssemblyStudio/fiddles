// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern "C" {
    pub fn aes(key: &str, data: &str) -> String;
}
#[wasm_bindgen]
pub fn s(data: &str) -> String {
    aes("090806fb005e4f61", data)
}