// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    type HTMLDocument;
    static document: HTMLDocument;
    #[wasm_bindgen(method)]
    fn createElement(this: &HTMLDocument, tagName: &str) -> Element;
    #[wasm_bindgen(method, getter)]
    fn body(this: &HTMLDocument) -> Element;

    type Element;
    #[wasm_bindgen(method, setter = innerHTML)]
    fn set_inner_html(this: &Element, html: &str);
    #[wasm_bindgen(method, js_name = appendChild)]
    fn append_child(this: &Element, other: Element);
    #[wasm_bindgen(method, js_name = setAttribute)]
    fn set_attribute(this: &Element, name: &str, value: &str);

    type SVGElement;
    type SVGText;
    type SVGTextPath;
    #[wasm_bindgen(method, js_name= viewbox)]
    fn viewbox(this: &SVGElement, x: &i32, y: &i32, width: &i32, height: &i32 ) -> SVGText;
    #[wasm_bindgen(method, js_name= text)]
    fn text(this: &SVGText, text: &str) -> SVGTextPath;
    #[wasm_bindgen(method, js_name= path)]
    fn path(this: &SVGTextPath, path: &str) -> SVGTextPath;
    #[wasm_bindgen(method, js_name= animate)]
    fn animate(this: &SVGTextPath, duration: &i32, place: &str) -> SVGTextPath;
    #[wasm_bindgen(method, js_name= plot)]
    fn plot(this: &SVGTextPath, vector: &str) -> SVGTextPath;
    #[wasm_bindgen(method, js_name= loop)]
    fn _loop(this: &SVGTextPath, on: bool, ever: bool);
    fn SVG(value: &str) -> SVGElement;

   
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
}
