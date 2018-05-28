#![feature(proc_macro, wasm_custom_section, wasm_import_module)]

extern crate wasm_bindgen;

use wasm_bindgen::prelude::*;

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
   
}

// Called by our JS entry point to run the example
#[wasm_bindgen]
pub fn run() {
    let rust = document.createElement("img");
    rust.set_attribute("src","https://upload.wikimedia.org/wikipedia/commons/thumb/d/d5/Rust_programming_language_black_logo.svg/2000px-Rust_programming_language_black_logo.svg.png");
    rust.set_attribute("width","40");
    rust.set_attribute("height","40");

    let span = document.createElement("span");
    span.set_inner_html(" says ");

    let hello = document.createElement("img");
    hello.set_attribute("src","https://static.wixstatic.com/media/2c9f2c_2b79872bcf7f458bbf27a9ad1d8acd74.png/v1/fill/w_590,h_313,al_c,usm_0.66_1.00_0.01/2c9f2c_2b79872bcf7f458bbf27a9ad1d8acd74.png");
    hello.set_attribute("width","40");
    hello.set_attribute("height","40");
    
    document.body().append_child(rust);
    document.body().append_child(span);
    document.body().append_child(hello);
}
