// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    pub type Map;
    #[wasm_bindgen(method, structural)]
    // fn get(this: &Map, key: u32) -> String;
    fn get(this: &Map, key: JsValue) -> JsValue;
    fn alert(s: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str, m: &Map) {
    let value = m.get(JsValue::from_f64(1 as f64));
    alert(&format!("Hello, {}, value: {:?}!", name, value.as_string()));
}
