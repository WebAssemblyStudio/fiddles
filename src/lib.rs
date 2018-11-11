#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;


#[wasm_bindgen]
extern {
    fn show_hash(s: &str);
}

pub fn hash(data: &[u8]) -> u32 {
  let mut res :u32  = 0;
  for byte in data.iter() {
    res += *byte as u32;
  }
  res
} 

#[wasm_bindgen]
pub fn hash_str(name: &str) {
    let hash = hash(name.as_bytes());
    show_hash(&format!("Der Hash ist {}!", hash));
}
