#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

const MEMORY_WIDTH: usize = 240_000 * 5;

#[wasm_bindgen]
pub struct Decoder {
    buffer1: [u8; MEMORY_WIDTH],
}

#[wasm_bindgen]
impl Decoder {
    #[wasm_bindgen(constructor)]
    pub fn new() -> Decoder {
        Decoder {
            buffer1: [0; MEMORY_WIDTH],
        }
    }
}
