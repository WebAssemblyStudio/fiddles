// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn jt_blockNumber();
    fn jt_getBalance(address: &str, currency: &str, issuer: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn blockNumber() {
    return jt_blockNumber();
}

#[wasm_bindgen]
pub fn root_balance() {
    return jt_getBalance("jHb9CJAWyB4jr91VRWn96DkukG4bwdtyTh", "", "");
}
