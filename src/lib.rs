#![feature(proc_macro, wasm_custom_section, wasm_import_module)]

extern crate wasm_bindgen;

use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern {
    #[wasm_bindgen(js_namespace = console)]
    fn log(s: &str);
}

#[derive(Debug)]
#[wasm_bindgen]
pub struct Counter {
    key: String,
    count: i32
}

#[wasm_bindgen]
impl Counter {
    pub fn default() -> Counter {
        log("Counter::default");
        Self::new("a".to_string(), 0)
    }
    pub fn new(key: String, count: i32) -> Counter {
        log(&format!("Counter::new({}, {})", key, count));
        Counter { key: key, count: count }
    }

    pub fn key(&self) -> String {
        log("Counter.key()");
        self.key.clone()
    }

    pub fn count(&self) -> i32 {
        log("Counter.count");
        self.count
    }

    pub fn increment(&mut self) {
        log("Counter.increment");
        self.count += 1;
    }

    pub fn update_key(&mut self, key: String) {
        self.key = key;
    }
}