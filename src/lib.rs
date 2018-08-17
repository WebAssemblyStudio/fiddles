#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern {
    pub type Map;
    #[wasm_bindgen(method, structural)]
    fn get(this: &Map, key: JsValue) -> JsValue;
    fn alert(s: &str);
}

#[wasm_bindgen]
pub fn greet(name: &str, m: &Map) {
    let value = m.get(JsValue::from_f64(1 as f64));
    alert(&format!("Hello, {}, value: {:?}!", name, value.as_string()));
}
