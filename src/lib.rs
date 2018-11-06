// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern "C" {
    type SVGElement;
    
    #[wasm_bindgen(method)]
    fn client_height(this: &SVGElement) -> i32;

    #[wasm_bindgen(method, js_name= viewbox)]
    fn viewbox(this: &SVGElement) -> SVGElement;
    #[wasm_bindgen(method, js_name= text)]
    fn text(this: &SVGElement, text: &str) -> SVGElement;
    #[wasm_bindgen(method, js_name= path)]
    fn path(this: &SVGElement, path: &str) -> SVGElement;
    #[wasm_bindgen(method, js_name= animate)]
    fn animate(this: &SVGElement, duration: i32, place: &str) -> SVGElement;
    #[wasm_bindgen(method, js_name= plot)]
    fn plot(this: &SVGElement, vector: &str) -> SVGElement;
    #[wasm_bindgen(method, js_name= loop)]
    fn _loop(this: &SVGElement, on: bool, ever: bool);
    fn SVG(value: &str) -> SVGElement;

    #[wasm_bindgen(js_namespace = console)]
    fn log(s: &SVGElement);
   
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn animate_code_dive() {
    let svg = SVG("drawing");
    //.viewbox();
    log(&svg);
}
