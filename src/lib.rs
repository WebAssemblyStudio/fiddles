// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
// #[wasm_bindgen]
// extern {
//     fn prompt(s: &str)->String;
// }

// #[wasm_bindgen]
// extern {
//   #[wasm_bindgen(js_namespace = console)]
//   fn log(s: &str);
// }

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn alloc(count:u32) -> Vec<i32> {
    let table = (0..count).map(|i| {
      i as i32
    })
    .collect();
    return table;
}
