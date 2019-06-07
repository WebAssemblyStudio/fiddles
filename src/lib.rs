// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

#[wasm_bindgen]
pub fn modl(p: i32, q: i32) -> i32 {
    p * q
}

#[wasm_bindgen]
pub fn keyd(p: i32, q: i32, e: i32) -> i32 {
    let eler = (p - 1) * (q - 1);
    let mut d = 0;
    
    for i in 0..eler {
        let res = (e * i) % eler;
        if res == 1 {
            d = i;
        }
    }
    d
}

#[wasm_bindgen]
pub fn cipher(data: &str, e: i32, n: i32) {
    let len = data.len();
    let mut ctext = Vec::new();
    for i in 0..len {
        let ch = &data[i..i+1].to_string().into_bytes()[0];
        let mut res = 1;
        for j in 0..e {
          res = (res * ch) % n as u8;
        }
        ctext.push(res);
    }
    alert(&format!("Cipher = {:?}", ctext));
}