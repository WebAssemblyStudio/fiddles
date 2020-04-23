extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

mod ext;

#[wasm_bindgen]
extern {
    #[wasm_bindgen(js_namespace = Math)]
    fn log2(a: f64) -> f64;
    #[wasm_bindgen(js_namespace = Math)]
    fn sin(a: f64) -> f64;
    #[wasm_bindgen(js_namespace = Math)]
    fn random() -> f64;

    #[wasm_bindgen(js_namespace = console)]
    fn log(a: &str);
}

macro_rules! println {
    ($($t:tt)*) => (log(&format_args!($($t)*).to_string()))
}

#[repr(u8)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Tile {
    Closed = 0,
    Open = 1,
}

const MAX_SIZE: usize = 640000;

#[wasm_bindgen]
pub fn get_max_size() -> usize {
  return MAX_SIZE;
}

#[wasm_bindgen]
pub fn run() -> *const u8 {
    //println!("Math.log2(10.0) = {}", log2(10.0));
    //println!("Math.sin(1) = {}", sin(ext::get_one()));
    let mut state = Box::new([123u8; MAX_SIZE]);

    for i in 0..MAX_SIZE {
      state[i] = (random() * 256 as f64).floor() as u8;
    }

    return state.as_ptr();
}