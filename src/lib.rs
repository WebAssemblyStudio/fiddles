#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern {
    pub type Map;
    #[wasm_bindgen(method, structural)]
    fn get(this: &Map, key: JsValue) -> JsValue;
    fn alert(s: &str);
    
    #[wasm_bindgen(constructor)]
    fn new() -> Map;
    #[wasm_bindgen(method, structural)]
    fn set(this: &Map, key: JsValue, value: JsValue);
}
#[wasm_bindgen]
pub fn greet(name: &str, m: &Map) {
    let new_map = Map::new();
    new_map.set(jsnum(1),jsnum(999));
    
    let value = m.get(jsnum(1));
    let value_new_map = new_map.get(jsnum(1));
    alert(&format!("Hello, {}, value: {:?}, other map: {:?}!", 
      name, value.as_string(), value_new_map.as_f64()));
}

fn jsnum(number: i32) -> JsValue {
  JsValue::from_f64(number as f64)
}
