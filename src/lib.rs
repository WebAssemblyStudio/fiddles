extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

mod ext;

#[wasm_bindgen]
extern {
    #[wasm_bindgen(js_namespace = Math)]
    fn log2(a: f64) -> f64;
    #[wasm_bindgen(js_namespace = Math)]
    fn sin(a: f64) -> f64;

    #[wasm_bindgen(js_namespace = console)]
    fn log(a: &str);
}

macro_rules! println {
    ($($t:tt)*) => (log(&format_args!($($t)*).to_string()))
}

const MAX_SIZE: usize = 50;

#[wasm_bindgen]
pub fn get_max_size() -> usize {
  return MAX_SIZE;
}

#[wasm_bindgen]
pub fn run() -> *const usize {
    //println!("Math.log2(10.0) = {}", log2(10.0));
    //println!("Math.sin(1) = {}", sin(ext::get_one()));
    let mut state = Box::new([123usize, MAX_SIZE]);

    return state.as_ptr();
}