#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

const MEMORY_WIDTH: usize = 240_000 * 3;

#[wasm_bindgen]
pub struct Decoder {
    buffer1: [u8; MEMORY_WIDTH],
    buffer2: [f32; MEMORY_WIDTH / 4],
}

#[wasm_bindgen]
impl Decoder {
    #[wasm_bindgen(constructor)]
    pub fn new() -> Decoder {
        Decoder {
            buffer1: [0; MEMORY_WIDTH],
            buffer2: [0.0; MEMORY_WIDTH / 4],
        }
    }
}
