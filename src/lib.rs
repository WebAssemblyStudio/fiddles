// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(const_fn, const_let, proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
}


/// Represents a chunk, returned from the FastCDC iterator.
#[derive(Debug, Clone, Copy, Eq, PartialEq, Hash)]
pub struct Chunk {
    /// Starting byte position within the original content.
    pub offset: usize,
    /// Length of the chunk in bytes.
    pub length: usize,
}

#[derive(Debug, Clone, Eq, PartialEq)]
pub struct RabinCDC<'a> {
    source: &'a [u8],
    bytes_processed: usize,
    bytes_remaining: usize,
    min_size: usize,
    avg_size: usize,
    max_size: usize,
    mask_s: u32,
    mask_l: u32,
    eof: bool,
}


pub const POLYNOMIAL_DEGREE:usize = 53;
pub const POLYNOMIAL_SHIFT:usize = POLYNOMIAL_DEGREE - 8;

fn degree(polynom: u64) -> i32 {
  return 63 - polynom.leading_zeros() as i32;
}


// static MOD_TABLE:[u32; 256] = init_mod_table();

// const fn init_mod_table() -> [u32; 256] {
//   let mut table:Vec<u32> = Vec::with_capacity(256);
//   table.push(1);

//   unsafe { table.into() }
// }


const TABLE: [usize; 5] = {
    let mut table:[usize; 5] = [0; 5];
    let mut i = 0;
    while i < 5 {
        table[i] = i * 10;
        i = i + 1;
    }
    table
};
