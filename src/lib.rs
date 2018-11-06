// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern "C" {
    type SVG;

    #[wasm_bindgen(method, structural)]
    fn viewbox(this: &SVG, x: i32, y:i32, width: i32, height: i32) -> SVG;
    #[wasm_bindgen(method, structural)]
    fn text(this: &SVG, text: &str) -> SVG;
    #[wasm_bindgen(method, structural)]
    fn path(this: &SVG, path: &str) -> SVG;
    #[wasm_bindgen(method, structural)]
    fn animate(this: &SVG, duration: u32, place: &str) -> SVG;
    #[wasm_bindgen(method, structural)]
    fn plot(this: &SVG, vector: &str) -> SVG;
    #[wasm_bindgen(method,setter = loop, structural)]
    fn _loop(this: &SVG, on: bool, ever: bool);
    fn SVG(value: &str) -> SVG;

    #[wasm_bindgen(js_namespace = console)]
    fn log(s: &SVG);

    #[wasm_bindgen(js_namespace = console, js_name = log)]
    fn log_u32(a: u32);
   
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn animate_code_dive() {
     SVG("drawing").viewbox(0,0,230, 230).text("code::dive")
              .path("M10 80 C 40 10, 65 10, 95 80 S 150 150, 180 80")
              .animate(1000,"<>")
              .plot("M10 80 C 40 150, 65 150, 95 80 S 150 10, 180 80")
              ._loop(true, true);
}
