// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Export JS functions for use in rust code
#[wasm_bindgen]
extern {
    fn alert(s: &str);
    fn clog(s: &str);
    fn eval(code: &str); // JS Portal
}

// Create Function to be used in JS
#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
    clog("test log to console");
    eval("alert('hi');");
}
