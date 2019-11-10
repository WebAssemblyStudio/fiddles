// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;



use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub struct Vector3 {
    x: f32,
    y: f32,
    z: f32,
}

#[wasm_bindgen]
impl Vector3 {
    #[wasm_bindgen(constructor)]
    pub fn new() -> Vector3 {
        Vector3 {
            x: 0.0,
            y: 0.0,
            z: 0.0,
        }
    }

    pub fn get_x(&self) -> f32 {
        self.x
    }
}

#[wasm_bindgen]
pub struct Group {
    list: Vec<Vector3>,
}

#[wasm_bindgen]
impl Group {
    #[wasm_bindgen(constructor)]
    pub fn new() -> Group {
        return Group { list: vec![] };
    }

    pub fn add(&mut self, vec: Vector3) {
        self.list.push(vec);
    }
}

