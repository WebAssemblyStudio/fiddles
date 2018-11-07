// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern "C" {
    type SVG;
    type FX;
    #[wasm_bindgen(method, structural)]
    fn viewbox(this: &SVG, x: i32, y:i32, width: i32, height: i32) -> SVG;
    #[wasm_bindgen(method, structural)]
    fn text(this: &SVG, text: &str) -> SVG;
    #[wasm_bindgen(method, structural)]
    fn path(this: &SVG, path: &str) -> SVG;
    #[wasm_bindgen(method, structural)]
    fn animate(this: &SVG, duration: u32, place: &str) -> SVG;
    #[wasm_bindgen(method, structural)]
    fn plot(this: &SVG, vector: &str) -> FX;
    #[wasm_bindgen(method, js_name = loop, structural)]
    fn _loop(this: &FX, on: bool, reserved: bool);
    fn SVG(value: &str) -> SVG;

    #[wasm_bindgen(js_namespace = console)]
    fn log(s: &SVG);

    #[wasm_bindgen(js_namespace = console, js_name = log)]
    fn log_u32(a: u32);
   
}

#[wasm_bindgen]
pub fn animate_code_dive(word: &str) {
    SVG("drawing").viewbox(0,0, 300, 130).text(word)
              .path("M1 1 C 65 10, 65 10, 95 80 S 150 100, 140 10")
              .animate(1000,"<>")
              .plot("M1 1 C 65 120, 65 120, 95 80 S 150 10, 140 10")
              ._loop(true, true);      
}
